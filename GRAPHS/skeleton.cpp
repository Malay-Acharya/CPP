#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vector<int>>
#define Mod 1e9 + 7
#define N 1e5
#define endl "\n"
#define deb(x) cout<<x<<endl

using namespace std;

int DFS(int a, int b, vvi adjl, vector<bool> &visited,int c)
{
    if(a==b)
    {
        return c;
    }
    visited[a] = 1;
    for(auto it: adjl[a])
    {
        if(!visited[it])
        {
            c++;
            return DFS(it,b,adjl,visited,c);
        }
    }
}

int dis(int a, int b, vvi adjl, int n)
{
    vector<bool> visited(n+1,0);
    return DFS(a,b,adjl,visited,0);
}

void solve()
{
    int n,q;
    cin >> n >> q;
    vvi adjl(n+1);
    int x,y;
    for(int i=0;i<n-1;i++)
    {
        cin >> x >> y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
    int a,b;
    while(q--)
    {
        int ans = 0;
        cin >> a >> b;
        for(int i =1;i<=n;i++)
        {
            if(i==a || i == b)
            continue;
            
            ans+= min(dis(a,i,adjl,n), dis(b,i,adjl,n));
        }
        cout<<ans<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin  >> t;
    while(t--)
    {
        solve();
    }
}
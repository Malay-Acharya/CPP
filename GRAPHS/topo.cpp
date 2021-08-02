#include <iostream>
#include <vector>
#include <queue>

#define vvi vector<vector<int>>
#define vi vector<int>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vvi adjl(n+1);
    vi indeg(n+1,0);
    for(int i =0;i<m;i++)
    {
        int x,y;
        cin >> x >>y;
        adjl[x].push_back(y);
        indeg[y]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indeg[i] == 0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int z = q.front();
        cout<<z<<" ";
        q.pop();
        for(auto it: adjl[z])
        {
            indeg[it]--;
            if(indeg[it] == 0)
            {
                q.push(it);
            }
        }
    }

}
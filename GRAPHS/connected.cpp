#include <iostream>
#include <vector>

#define vvi vector<vector<int>> 
#define vi vector<int>

using namespace std;

void DFS(int n, vector<bool> &visited, vvi adjl)
{
    visited[n] = 1;
    for(auto it: adjl[n])
    {
        if(!visited[it])
        DFS(it,visited,adjl);
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    vvi adjl(n+1);
    int sz = 0;
    vector<bool> visited(n+1, 0);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
    for(int i =1;i<=n;i++)
    {
        if(!visited[i])
        {
            sz++;
            DFS(i,visited,adjl);
        }
    }
    cout<<sz<<endl;

}
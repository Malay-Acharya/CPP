#include <iostream>
#include <vector>
#include <queue>

#define vvi vector<vector<int>>
#define vi vector<int>

using namespace std;

bool cyclee(int src, vvi &adjl,vector<bool> &visited, int parent)
{
    visited[src] = 1;
    for(auto it: adjl[src])
    {
        if(it!=parent)
        {
            if(visited[it])
            {
                return true;
            }
            else if(!visited[it] && cyclee(it,adjl,visited,src))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vvi adjl(n+1);
    vector<bool> visited(n+1, 0);

    for(int i =0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
    bool cycle = false;
    for(int i =1;i<=n;i++)
    {
        if(!visited[i] && cyclee(i,adjl,visited,-1))
        cycle = true;
    }
    if(cycle == true)
    {
        cout<<"CYCLE IS PRESENT"<<endl;
    }
    else
    {
        cout<<"NO CYCLE DETECTED"<<endl;
    }
}
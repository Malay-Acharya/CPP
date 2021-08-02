#include <iostream>
#include <vector>

#define vvi vector<vector<int>> 
#define vi vector<int>

using namespace std;

bool cyclee(int src, vvi &adjl,vector<bool> &visited, vi &stack)
{
    stack[src] = 1;
    if(!visited[src])
    {
        visited[src] = 1;
        for(auto it:adjl[src])
        {
            if(!visited[it] && cyclee(it,adjl,visited,stack))
            return true;
            if(stack[it])
            return true;
        }
    }
    stack[src] = 0;
    return false;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vvi adjl(n+1);
    vi stack(n+1, 0);
    vector<bool> visited(n+1,0);
    for(int i =0;i<m;i++)
    {
        int x,y;
        cin >> x >>y;
        adjl[x].push_back(y);
    }
    bool cycle = false;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && cyclee(i,adjl,visited,stack))
        {
            cycle = true;
        }
    }
    if(cycle == true)
    {
        cout<<"Cycle is Present"<<endl;
    }
    else
    {
        cout<<"Cycle not Present"<<endl;
    }
}
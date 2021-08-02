#include <iostream>
#include <vector>

#define vvi vector<vector<int>> 
#define vi vector<int>

using namespace std;

bool bipart = true;

void color(int i, int col, vi &colour, vvi &adjl, vector<bool> &visited)
{
    if(colour[i] != -1 && colour[i] != col)
    {
        bipart = false;
        return;
    }
    colour[i] =  col;
    if(visited[i])
    return;

    for(auto it:adjl[i])
    {
        color(i,(col^1),colour,adjl,visited);
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    vvi adjl(n+1);
    vector<bool> visited(n+1,0);
    vi colour(n+1,-1);
    for(int i =0;i<m;i++)
    {
        int x,y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
    for(int i =1;i<=n;i++)
    {
        if(!visited[i])
        {
            color(i,0,colour,adjl,visited);
        }
    }
    if(bipart)
    cout<<"BIPART"<<endl;
    else
    cout<<"NOT BIPART"<<endl;
}
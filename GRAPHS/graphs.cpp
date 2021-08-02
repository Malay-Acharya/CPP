#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5+2;
vector<int> adjl[N];
bool vis[N] = {0};
bool visd[N] = {0};

void BFS(vector<int> adjl[])
{
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        cout<<n<<" ";
        vector<int> :: iterator it;
        for(it = adjl[n].begin();it!=adjl[n].end();++it)
        {
            if(!vis[*it])
            {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }
}

void DFS(int node, vector<int> adjl[])
{
    //preorder
    visd[node] = 1;
    cout<<node<<" ";

    //inorder
    vector<int> :: iterator it;
    for(it = adjl[node].begin(); it != adjl[node].end();++it)
    {
        if(!visd[*it])
        {
            DFS(*it,adjl);
        }
    }

    //postorder


    cout<<endl;
}

int main()
{
    int n, m,x,y;
    cin >> n >> m;
    for(int i =0;i<m;i++)
    {
        cin >> x >> y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
    BFS(adjl);
    DFS(1,adjl);
}
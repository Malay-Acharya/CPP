#include <iostream>
#define int long long
using namespace std;
const int N = 1e3+2;

int w[N];
int val[N];
int dp[N][N];

int O1knap(int n, int x)
{
    if(x <= 0)
    return 0;

    if(n<=0)
    return 0;

    if(w[n-1] > x)
    return O1knap(n-1,x);

    if(dp[n][x] != -1)
        return dp[n][x];

    dp[n][x] = max(O1knap(n-1,x), (O1knap(n-1,x-w[n-1]) + val[n]));

    return dp[n][x];
}

signed main()
{
    int n;
    cin >> n;
    for(int i =0;i<N;i++)
    {
        for(int j =0;j<N;j++)
            dp[i][j] = -1;
    }
    for(int i =0;i<n;i++)
        cin >> w[i];

    for(int i =0;i<n;i++)
        cin >> val[i];

    int x;
    cin >> x;

    cout << O1knap(n,x)<<endl;
}
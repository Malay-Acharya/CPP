#include <iostream>
#define int long long

using namespace std;

const int N = 1e3+2;
const int MOD = 1e9+7;

int dp[N][N];

int coinch(int arr[], int n, int x)
{
    if(x==0)
    return 1;

    if(x<0)
    return 0;

    if(n<=0 && x>0)
    return 0;

    if(dp[n][x] != -1)
    return dp[n][x];

    dp[n][x] = coinch(arr,n,x-arr[n-1]) + coinch(arr,n-1,x);

    return dp[n][x];
}

signed main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i =0;i<n;i++)
    {
        cin >> arr[i];
    }
    for(int i =0;i<N;i++)
    {
        for(int j=0;j<N;j++)
         dp[i][j] = -1;
    }
    int x;
    cin >> x;
    cout<<coinch(arr,n,x);
}
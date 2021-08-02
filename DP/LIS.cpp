#include <iostream>
#include <vector>

#define vi vector<int>
#define rep(i,j,k) for(int i = j;i<k;i++)
#define int long long

using namespace std;

const int N = 1e5+2;
int dp[N];

int lis(vi &v, int n)
{

    if(dp[n] != -1)
        return dp[n];

    dp[n] = 1;
    rep(i,0,n)
    {
        if(v[n] > v[i])
            dp[n] = max(dp[n], 1+lis(v,i));
    }
    return dp[n];
}

signed main()
{

    int n;
    cin >> n;

    rep(i,0,n)
        dp[i] = -1;


    vi v(n);
    rep(i,0,n)
    {
        cin >> v[i];
    }
    cout<<lis(v,n-1)<<endl;
}
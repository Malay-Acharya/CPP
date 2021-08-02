#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define rep(i,j,k) for(int i = j;i<k;i++)
#define int long long

using namespace std;

const int N = 1e3+2;

int dp[N][N];
int LCS(string a, string b, int n1, int n2)
{
    if(n1==0 || n2==0)
        return 0;
    if(dp[n1-1][n2-1] != -1)
        return dp[n1-1][n2-1];

    if(a[n1-1] == b[n2-1])
        dp[n1-1][n2-1] = (1+LCS(a,b,n1-1,n2-1));

    else
    {
        dp[n1-1][n2-1] = max(LCS(a,b,n1,n2-1),LCS(a,b,n1-1,n2));
    }

    return dp[n1-1][n2-1];
}


signed main()
{
    string a,b;
    cin >> a >> b;
    int n1 = a.size();
    int n2 = b.size();
    rep(i,0,n1)
    {
        rep(j,0,n2)
        dp[i][j] =-1;
    }
    cout<<LCS(a,b,n1,n2)<<endl;
}
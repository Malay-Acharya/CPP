#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5;
const int MOD = 1e9+7;
int dp[N] = {0};
int minsq(int n)
{
  if(n==0||n==1||n==2||n==3)
  return n;
  if(dp[n]!=0)
    return dp[n];

  int ans = MOD;
  for(int i = 1;i*i<=n;i++)
  {
    dp[n] = min(dp[i], (1+minsq(n-pow(i,2))));
  }
  return dp[n];
}

signed main()
{
  for(int i =0;i<=N;i++)
  dp[i] = MOD;
  
  int n;
  cin >> n;
  

  cout<<minsq(n)<<endl;
}


#include <iostream>
#define int long long
using namespace std;

const int N = 1e5;
int dp[N] = {0};

int fib(int n)
{
  if(n==0)
  return 0;
  if(n==1 || n==2)
  return 1;
  
  if(dp[n]!=0)
  return dp[n];

  dp[n] = fib(n-1) + fib(n-2);
  return dp[n];
}
signed main() {
  int n;
  cin >> n;
  cout<<fib(n)<<endl;
}
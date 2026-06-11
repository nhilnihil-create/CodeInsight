#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int n,T;
  cin >> n >> T;
  
  int t[n];
  rep(i,n) cin >> t[i];
  
  ll ans = 0;
  for(int i = 0; i < n-1; i++)
  { 
    if(t[i+1] - t[i] < T)
    {
      ans += t[i+1] - t[i];
    }else
    {
      ans += T;
    }
  }
  
  ans += T;
  
  cout << ans << endl;
    
}
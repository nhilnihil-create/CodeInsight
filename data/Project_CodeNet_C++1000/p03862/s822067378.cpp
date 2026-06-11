#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  
  ll res = 0;
  if(a[0] > x) res += a[0]-x, a[0]=x;
  rep(i,n-1)
  {
    if(a[i+1]+a[i] > x)
    {
      res += a[i] + a[i+1] - x;
      a[i+1] = x - a[i];
    }
  }
  cout << res << endl;
  
  return 0;
}
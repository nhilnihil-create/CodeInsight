#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  int i;
  rep(i,n) cin >> a[i];
  ll ans = 0;
  ll sums = 0;
  rep(i,n)
  {
    if(a[i] == 0)
    {
      ans += sums/2;
      sums = 0;
    }
    else sums += a[i];
  }
  ans += sums/2;
  cout << ans << endl;
}
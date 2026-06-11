#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
  ll n, t;
  cin >> n >> t;
  
  vector<ll> a(n, 0);
  for(ll i = 0; i < n; i++)
    cin >> a[i];
  
  ll ans = t;
  for(ll i = n-1; i >= 1; i--)
  {
    if( a[i]-a[i-1] >= t)
      ans += t;
    else
      ans += (a[i]-a[i-1]);
  }
  
  cout << ans << endl;
  return 0;
}
  
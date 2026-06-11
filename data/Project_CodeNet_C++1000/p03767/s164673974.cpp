#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 1000000000;
int main()
{
  ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
  ll n;
  cin>>n;
  n*=3;
  ll a[n];
  rep(i,n) cin >> a[i];
  sort(a,a+n);
  ll ans = 0, count = 0;
  for(int i=n-2;i>n/3-1;i-=2) {
      ans+= a[i];
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n; cin >> n;
  vector<ll> a;

  rep(i, 3*n) {
    ll tmp; cin>>tmp;
    a.push_back(tmp);
  }

  sort(a.begin(), a.end());

  ll ans=0;
  for (int i=0, j=a.size()-2; i < n; i++, j-=2) {
    ans+= a[j];
  }
  // while (true) {
  //   ans += a[a.size()-2];

  //   a.erase(a.begin());
  //   a.pop_back();
  //   a.pop_back();
  //   if(a.size() == 0) break;
  // }
  cout << ans << endl;

  return 0;
}
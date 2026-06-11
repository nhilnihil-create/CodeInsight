#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> p(n + 1);
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    p[a[i]] = i;
  }

  ll ans = 0;
  set<ll> s;
  set<ll> s2;
  for (int i = 1; i <= n; i++){
    auto r = s.lower_bound(p[i]);
    auto r2 = s2.lower_bound(-p[i]);
    if (r == s.end()){
      if (i == 1){
        ans += i*(n - p[i]) * (p[i] + 1);
      }
      else {
        auto l = prev(r, 1);
        ans += i*(n - p[i]) * (p[i] - *l);
      }
    }
    else {
      auto l = r2;
      if (l == s2.end()){
        ans += i*(*r - p[i]) * (p[i] + 1);
      }
      else {
        ans += i*(*r - p[i]) * (p[i] + *l);
      }
    }

    s.insert(p[i]);
    s2.insert(-p[i]);
  }
  cout << ans << endl;
  

  return 0;
}

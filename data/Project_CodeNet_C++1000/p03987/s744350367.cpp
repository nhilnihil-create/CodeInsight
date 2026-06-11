#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll N;
  cin >> N;
  int a[N];
  ll ans = 0;
  ll where[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    a[i]--;
    where[a[i]] = i;
  }
  set<ll> Set;
  Set.insert(-1LL);
  Set.insert(N);
  for (ll i = 0; i < N; i++) {
    auto itr = Set.lower_bound(where[i]);
    auto itr2 = prev(itr,1);
    ll res = (*itr - where[i]) * (where[i] - *itr2) * (i + 1); 
    ans += res;
    Set.insert(where[i]);
  }
  cout << ans << endl;
  return 0;
}
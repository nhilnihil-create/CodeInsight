#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  set<ll> st;
  for (int i = 0; i < N; i++) {
    ll a; cin >> a;
    st.insert(a);
  }
  ll ans = st.size();
  if (ans % 2 == 0) ans--;
  cout << ans << '\n';
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  vector < int > pos (n + 1);
  for (int i = 1; i <= n; i++) {
    int a; cin >> a;
    pos[a] = i;
  }

  ll ans = 0;
  set < int > s;
  s.insert (0);
  s.insert (n + 1);
  for (int i = 1; i <= n; i++) {
    int idx = pos[i];
    auto it = s.lower_bound (idx);
    int r = *it - 1, l = *(--it) + 1;
    ans += (ll)(r - idx + 1) * (idx - l + 1) * (ll)i;
    s.insert (idx);
  }

  cout << ans << '\n';
}

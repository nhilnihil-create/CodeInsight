#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

set<pii> win;
set<pii> seen;
bool wins(int a, int b) {
  if(seen.count({a, b})) return win.count({a, b});
  seen.insert({a, b});
  bool ret = false;
  for(int i = 2; i <= a; i += 2) {
    ret |= !wins(a-i, b+i/2);
  }
  for(int i = 2; i <= b; i += 2) {
    ret |= !wins(a+i/2, b-i);
  }
  if(ret) win.insert({a, b});
  return ret;
}

void solve() {
  ll a, b;
  cin >> a >> b;
  if(abs(a-b) <= 1) cout << "Brown\n";
  else cout << "Alice\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}

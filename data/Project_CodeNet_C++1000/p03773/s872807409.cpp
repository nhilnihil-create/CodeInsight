/*
 *  WATCH THIS
 */
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll N = 1e7, oo = LONG_LONG_MAX, mod = 24;

void debug() { cerr << endl; }

template<typename Head, typename... Tail>
void debug(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug(T...);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, a;
  cin >> n >> a;
  int ans = (n % mod + a % mod) % mod;
  cout << ans << endl;
  return 0;
}
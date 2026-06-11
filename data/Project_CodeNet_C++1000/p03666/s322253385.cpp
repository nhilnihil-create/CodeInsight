#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

signed main() {
  ll N,A,B,C,D;
  cin>>N>>A>>B>>C>>D;
  bool ok = false;
  for (ll x = 1; x <= N; x++) {
    ll ly1 = A+C*(x-1);
    ll uy1 = A+D*(x-1);

    ll ly2 = B+C*(N-x);
    ll uy2 = B+D*(N-x);
    if (uy1 < ly2)
      continue;
    if (uy2 < ly1)
      continue;
    ok = true;
  }
  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

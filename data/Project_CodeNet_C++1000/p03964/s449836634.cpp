// 20
/****************************************************
https://searleser97.gitlab.io/algorithms/template.cpp
****************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define forr(_, x, n) for (int _ = x; _ > n; _--)
#define fos(_, x, n, s) for (int _ = x; _ < n; _ += s)
#define forn(_, x, n) fos(_, x, n, 1)
#define rep(_, n) forn(_, 0, n)
#define fi first
#define se second
#define pb push_back
#define pairii pair<int, int>
#define all(x) x.begin(), x.end()
#define cerr(s) cerr << "\033[48;5;196m\033[38;5;15m" << s << "\033[0m"
// typedef __int128_t lli;
typedef long long int li;
typedef long double ld;
// 12
void _main(int tc) {
  int n;
  cin >> n;
  li sumt = 0, suma = 0;
  rep(i, n) {
    li t, a;
    cin >> t >> a;
    if (i == 0) sumt = t, suma = a;
    else {
      // li m1 = ceil((double) sumt / t);
      // li m2 = ceil((double) suma / a);
      li m1 = sumt % t == 0 ? sumt / t : sumt / t + 1;
      li m2 = suma % a == 0 ? suma / a : suma / a + 1;
      li multi = max(m1, m2);
      sumt = t * multi, suma = a * multi;
    }
  }

  cout << sumt + suma << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}
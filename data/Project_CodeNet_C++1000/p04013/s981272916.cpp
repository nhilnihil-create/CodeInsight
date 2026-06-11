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

// li dp(int sum, vector<int>& v, int pos, vector<vector<vector<li>>> &mem, int need) {
//   if (pos == v.size()) {
//     if (sum == 0 && need == 0) return 1;
//     else return 0;
//   }
//   if (sum == 0 && need == 0) return 1;
//   if (sum < 0) return 0;
//   if (need < 0) return 0;
//   if (mem[pos][sum][need] != -1) return mem[pos][sum][need];
//   return mem[pos][sum][need] = dp(sum - v[pos], v, pos + 1, mem, need - 1) + dp(sum, v, pos + 1, mem, need);
// }

li dp(int sum, vector<int>& v, int pos, vector<vector<vector<li>>>& mem, int cnt, int a) {
  if (pos == v.size()) {
    if (cnt == 0) return 0;
    if (sum % cnt == 0) {
      if (sum / cnt == a) {
        return 1;
      } else {
        return 0;
      }
    } else {
      return 0;
    }
  }
  if (mem[pos][sum][cnt] != -1) return mem[pos][sum][cnt];
  return mem[pos][sum][cnt] = dp(sum + v[pos], v, pos + 1, mem, cnt + 1, a) + dp(sum, v, pos + 1, mem, cnt, a);
}

void _main(int tc) {
  int n, a;
  cin >> n >> a;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  vector<vector<vector<li>>> mem(51, vector<vector<li>>(50 * 50 + 1, vector<li>(51, -1)));
  // vector<vector<li>> mem(50 + 1, vector<li>())
  // li ans = 0;
  // for (int i = 1; i <= n; i++) {
  //   ans += dp(i * a, v, 0, mem, i);
  // }
  li ans = dp(0, v, 0, mem, 0, a);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}
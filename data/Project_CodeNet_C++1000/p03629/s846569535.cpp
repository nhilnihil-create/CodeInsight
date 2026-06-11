#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repi(i, a, b) for (int i = (a); i < int(b); i++)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ll << (b))
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define rsort(v) sort(all(v)); reverse(all(v))

using namespace std;
using i32 = int;
using i64 = long long;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

inline void ioinit() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); }
inline i64 gcd(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); if (a % b == 0) return b; return gcd(b, a % b); }
inline i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }
inline vi32 plist(i32 n) { vi32 f(n, 1); f[0] = f[1] = 0; repi(i, 2, n) for (int j = i * 2; j < n; j += i) f[j] = 0; return f; }
inline bool isprime(i32 n) { if (n < 2) return 0; for (i32 i = 2; i * i <= n; i++) if (n % i == 0) return 0; return 1; }
template<class T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template<class T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template<class T> inline bool amax(T &x, T y) { if (x < y) return 0; x = y; return 1; }
template<class T> inline bool amin(T &x, T y) { if (x > y) return 0; x = y; return 1; }
template<class T> inline i64 lbi(vector<T> &v, T e) { return lower_bound(all(v), e) - v.begin(); }
template<class T> inline i64 ubi(vector<T> &v, T e) { return upper_bound(all(v), e) - v.begin(); }
template<class T> inline T power(T x, i64 n) { T r = 1; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }

vector<vi32> calcNext(const string &s) {
  int n = s.size();
  // 文字cが存在しないときのインデックスはn
  // 文字列の長さがnなので、nは範囲外を表すものとして最適なのかも
  vector<vi32> res(n + 1, vi32(26, n));
  rrep(i, n) {
    rep(j, 26) res[i][j] = res[i + 1][j];
    res[i][s[i] - 'a'] = i;
  }
  return res;
}

int main() {
  ioinit();
  string s;
  cin >> s;
  int n = s.size();
  auto next = calcNext(s);
  vi32 dp(n + 1, bit(30));
  dp[n] = 1;
  rrep(i, n) rep(j, 26) {
    if (next[i][j] == n) {
      dp[i] = 1;
    } else {
      amax(dp[i], dp[next[i][j] + 1] + 1);
    }
  }
  string ans = "";
  int i = 0;
  while (i < n) {
    rep(j, 26) {
      if (next[i][j] == n || dp[next[i][j] + 1] + 1 == dp[i]) {
        ans += 'a' + j;
        i = next[i][j] + 1;
        break;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}

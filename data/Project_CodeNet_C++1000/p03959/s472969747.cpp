/*
　　　 _,,..,,,,_
　　 / ,' 3　 `ヽｰっ
.　　l　　 ⊃　⌒_つ
　　 `'ｰ---‐'''''"
*/
#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) \
  for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) \
  for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define VREP(s, ite) for (auto ite = s.begin(); ite != s.end(); ++ite)
#define FI first
#define SE second
#define ALL(v) v.begin(), v.end()
//#define endl "\n"
#define ciosup \
  cin.tie(0);  \
  ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e15 + 7LL;
constexpr ll MOD = 1e9 + 7LL;
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (int i = 0; i < v.size(); ++i) {
    is >> v[i];
  }
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < v.size() - 1; ++i) {
    os << v[i] << " ";
  }
  if (v.size() > 0) {
    os << v[v.size() - 1] << endl;
  }
  return os;
}

int main() {
  int n;
  cin >> n;
  vll t(n), a(n);
  cin >> t >> a;
  if (n == 1){
    if (a[0] != t[0]){
      cout << 0 << endl;
    }else{
      cout << 1 << endl;
    }
    return 0;
  }
  if ((a[0] > a[1] && t[0] != a[0]) || (t[0] > a[0])){
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1;
  FOR(i, 1, n-1){
    if (a[i] > a[i+1] && t[i-1] < t[i]){
      if (a[i] != t[i]){
        cout << 0 << endl;
        return 0;
      }
    }else if (a[i] > a[i+1]){
      if (a[i] > t[i]) {
        cout << 0 << endl;
        return 0;
      }
    } else if (t[i - 1] < t[i]) {
      if (a[i] < t[i]) {
        cout << 0 << endl;
        return 0;
      }
    } else {
      ans = (ans * min(a[i], t[i])) % MOD;
    }
  }
  if ( (t[n-2] < t[n-1] && t[n-1] != a[n-2]) || (t[n-1] < a[n-1]) ){
    cout << 0 << endl;
    return 0;
  }
  cout << ans << endl;
}
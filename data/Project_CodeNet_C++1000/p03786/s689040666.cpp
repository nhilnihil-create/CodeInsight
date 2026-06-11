#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout(val) cout << std::fixed << std::setprecision(20) << val;
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());

  int cant = 0;
  ll sum = a[0];
  rep1(i, n - 1) {
    if(a[i] > sum * 2) {
      cant = i;
    }
    sum += a[i];
  }

  cout << n - cant << endl;
}

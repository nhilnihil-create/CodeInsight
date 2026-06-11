#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout(val) cout << std::fixed << std::setprecision(20) << val;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x,y; cin >> x >> y;

  if(x == 0) {
    int ans = signbit(y) + abs(y);
    cout << ans << endl;
    return 0;
  } else if(y == 0) {
    int ans = !signbit(x) + abs(x);
    cout << ans << endl;
    return 0;
  }

  int ans = 0;
  if(abs(x) < abs(y)) {
    if(signbit(x) && signbit(y)) {
      ans += 2;
    } else if(signbit(x) || signbit(y)) {
      ++ans;
    }
  } else {
    if(!signbit(x) && !signbit(y)) {
      ans += 2;
    } else if(!signbit(x) || !signbit(y)) {
      ++ans;
    }
  }

  ans += abs(abs(x) - abs(y));

  cout << ans << endl;
}

// -10 -20 -> 12
// -10  20 -> 11
//  10 -20 -> 11
//  10  20 -> 10
//   0  10 -> 10

// -20 -10 -> 10
//  20 -10 -> 11
// -20  10 -> 11
//  20  10 -> 12
//   0 -10 -> 11

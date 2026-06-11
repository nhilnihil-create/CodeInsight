#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n;
  cin >> n;
  int a[n];
  REP(i, n) cin >> a[i];
  int mx = 0, mn = n;
  REP(i, n) {
    mx = max(mx, a[i]);
    mn = min(mn, a[i]);
  }
  if (mx == mn) {
    REP(i, n) {
      if (a[i] != n - 1 && 2 * a[i] > n) {
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
  } else if (mx - mn == 1) {
    int y = 0;
    REP(i, n) {
      if (a[i] == mx) y++;
    }
    int x = n - y;
    if (x < mx && 2 * (mx - x) <= y) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    cout << "No" << endl;
  }
  return 0;
}
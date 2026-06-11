#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

int solve(int a, int b) {
  if (a <= b) {
    int rez = b - a;
    if (-a <= b) {
      rez = min(rez, b + a + 1);
    }
    if (a <= -b) {
      rez = min(rez, -b - a + 1);
    }
    return rez;
  }
  else {
    int rez = 2e9 + 20;
    if (a <= -b || b < 0) {
      rez = min(rez, 1 + solve(a, -b));
    }
    if (-a <= b || a < 0) {
      rez = min(rez, 1 + solve(-a, b));
    }
    rez = min(rez, 2 + solve(-a, -b));
    return rez;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a, b;
  cin >> a >> b;
  cout << solve(a, b) << '\n';
} 
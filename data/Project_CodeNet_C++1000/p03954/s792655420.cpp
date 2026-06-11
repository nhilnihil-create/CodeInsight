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

const int N = 2e5 + 10;
int a[N], b[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  n = 2 * n - 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }  
  int l = 1, r = n + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    for (int i = 1; i <= n; i++) {
      b[i] = (a[i] >= mid ? 1 : 0);
    }
    pair<int, int> best = {n + 1, -1};
    int ps = (n + 1) / 2;
    for (int i = 1; i < n; i++) {
      if (b[i] == b[i + 1]) {
        best = min(best, make_pair(abs(ps - i), b[i]));
        best = min(best, make_pair(abs(ps - (i + 1)), b[i]));
      }
    }
    if (best.F == n + 1) {
      if (b[1] == 1) {
        l = mid;
      }
      else {
        r = mid;
      }
    }
    else {
      if (best.S == 1) {
        l = mid;   
      }
      else {
        r = mid;
      }
    } 
  }
  cout << l << '\n'; 
} 
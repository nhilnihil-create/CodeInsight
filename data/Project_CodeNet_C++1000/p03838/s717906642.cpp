#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

int cal(int a, int b) {
  if (a <= b) return b - a;
  else return 2e9;
}

void MAIN() {
  int a, b;
  cin >> a >> b;
  cout << min(
    min(cal(a, b), cal(-a, b) + 1),
    min(cal(a, -b) + 1, cal(-a, -b) + 2)
  );
}

signed main() {
  // ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}

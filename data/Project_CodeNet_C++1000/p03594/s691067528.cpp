#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<unsigned char, unsigned char> pcc;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> matrix;

void solve() {
  int r, c, d;
  cin >> r >> c >> d;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      int x = (i+j);
      int y = (i-j);
      x %= (2*d);
      y %= (2*d);
      x += (2*d);
      y += (2*d);
      x %= (2*d);
      y %= (2*d);
      if(x < d && y < d) cout << "R";
      if(x < d && y >= d) cout << "Y";
      if(x >= d && y < d) cout << "G";
      if(x >= d && y >= d) cout << "B";
    }
    cout << "\n";
  }
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ":" << "\n";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}

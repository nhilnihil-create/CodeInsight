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

ll l[7];
void solve() {
  for(int i = 0; i < 7; i++) cin >> l[i];
  ll ret = l[1];
  ll a = 2*(l[3]/2) + 2*(l[4]/2) + 2*(l[0] / 2);
  ll b = 0;
  if(l[0] > 0 && l[3] > 0 && l[4] > 0) {
    b = 3 + 2*((l[0] - 1)/2) + 2*((l[3] - 1)/2) + 2*((l[4] - 1)/2);
  }
  cout << ret + max(a, b) << "\n";
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

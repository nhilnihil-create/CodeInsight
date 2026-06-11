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
typedef pair<ll, ll> pll;
typedef pair<double, int> pdi;

ll l[100005];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  ll ret = l[0] - 1;
  l[0] = 1;
  for(int i = 1; i < n; i++) {
    if(l[i] == l[i-1]) continue;
    if(l[i] == l[i-1] + 1) continue;
    ret += (l[i] - 1) / (l[i-1] + 1);
    l[i] = l[i-1];
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}

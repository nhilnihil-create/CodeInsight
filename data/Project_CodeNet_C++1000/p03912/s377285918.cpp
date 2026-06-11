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
typedef pair<int, ll> pill;

int modCount[100005];
int pairs[100005];
void solve() {
  int n, m;
  cin >> n >> m;
  map<int, int> dp;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    modCount[t%m]++;
    dp[t]++;
  }
  for(auto x: dp) {
    pairs[(x.first%m)] += x.second / 2;
  }
  int ret = 0;
  {
    int zero = modCount[0]/2;
    ret += zero;
    modCount[0] -= 2 * zero;
  }
  {
    if(m%2 == 0) {
      int zero = modCount[m/2]/2;
      ret += zero;
      modCount[m/2] -= 2 * zero;
    }
  }
  for(int i = 1; i < m-i; i++) {
    int j = m-i;
    int take = min(modCount[i], modCount[j]);
    modCount[i] -= take;
    modCount[j] -= take;
    ret += take;
  }
  for(int i = 0; i < m; i++) {
    ret += min(pairs[i], modCount[i]/2);
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

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

ll l[1000000];
ll pref[1000000];
ll suff[1000000];
ll prefSum[1000000];
int n;

void solve() {
  int k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    prefSum[i+1] = prefSum[i] + l[i];
  }
  for(int i = 0; i < n; i++) {
    pref[i+1] = pref[i] + max(0LL, l[i]);
  }
  for(int i = n-1; i >= 0; i--) {
    suff[n-i] = suff[n-i-1] + max(0LL, l[i]);
  }
  ll ret = 0;
  for(int i = 0; i + k <= n; i++) {
    ll cand = pref[i] + suff[n-k-i];
    cand += max(0LL, prefSum[i+k] - prefSum[i]);
    ret = max(ret, cand);
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
  solve();
}

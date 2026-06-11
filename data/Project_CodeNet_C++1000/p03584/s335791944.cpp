#include <algorithm>
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
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef vector<vector<ll>> matrix;

int n, k;
int mask[100005];
int util[100005];

ll sumOf(int match) {
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    if((mask[i] & match) == mask[i]) ret += util[i];
  }
  return ret;
}

void solve() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> mask[i] >> util[i];
  ll ret = sumOf(k);
  for(int bit = 1; bit < 30; bit++) {
    if(k&(1<<bit)) {
      int off = (1<<bit)-1;
      int nextM = k ^ (1<<bit) | off;
      ret = max(ret, sumOf(nextM));
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}

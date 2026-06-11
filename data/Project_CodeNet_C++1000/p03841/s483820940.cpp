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

int loc[501];
int ret[501*501];

void die() {
  cout << "No\n";
  exit(0);
}

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n*n; i++) ret[i] = -1;
  vector<pii> v;
  for(int i = 0; i < n; i++) {
    cin >> loc[i];
    loc[i]--;
    ret[loc[i]] = i;
    v.push_back({loc[i], i});
  }
  sort(v.begin(), v.end());
  map<int, int> left;
  for(int i = 1; i < n; i++) left[i] = i;
  for(int i = 0; i < n*n; i++) {
    if(ret[i] >= 0) {
      if(left.count(ret[i])) {
        die();
      }
      if(ret[i] != n-1) left[ret[i]] = n-1-ret[i];
      v.push_back(v[0]);
      v.erase(v.begin());
      continue;
    }
    int use = -1;
    for(pii out: v) {
      if(left.count(out.second)) {
        use = out.second;
        break;
      }
    }
    if(use < 0) die();
    if(--left[use] == 0) left.erase(use);
    ret[i] = use;
  }
  cout << "Yes\n";
  for(int i = 0; i < n*n; i++) {
    cout << ++ret[i];
    if(i == n*n-1) cout << "\n";
    else cout << " ";
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

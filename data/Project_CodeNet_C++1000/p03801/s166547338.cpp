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
typedef pair<ll, int> query;
typedef vector<vector<ll>> matrix;

int n;
map<int, ll> numToCount;
map<int, int> numToMin;
ll ret[100005];
void solve() {
  cin >> n;
  int idx = n;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if(numToCount[t]++ == 0) {
      numToMin[t] = i;
    }
  }
  int lastNum = numToMin.rbegin()->first;
  ll amt = 0;
  while(numToCount.size()) {
    int currNum = numToCount.rbegin()->first;
    ret[idx] += (lastNum - currNum) * amt;
    idx = min(idx, numToMin.rbegin()->second);
    amt += numToCount[currNum];
    numToCount.erase(currNum);
    numToMin.erase(currNum);
    lastNum = currNum;
  }
  ret[idx] += amt * lastNum;
  for(int i = 0; i < n; i++) cout << ret[i] << "\n";
}

void casesolve() {
  int t;
  cin >> t; cin.ignore();
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}

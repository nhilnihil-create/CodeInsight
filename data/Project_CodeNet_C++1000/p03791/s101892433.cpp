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
int l[100005];
const int MOD = 1000000007;
void solve() {
  cin >> n;
  int i = 0;
  ll ret = 1;
  for(int qq = 0; qq < n; qq++) {
    cin >> l[i];
    if(i) {
      l[i] = min(l[i], l[i-1] + 2);
    }
    else {
      l[i] = min(1, l[i]);
    }
    if(i && l[i] == l[i-1]+1) {
      ret *= i+1;
      ret %= MOD;
    }
    else {
      i++;
    }
  }
  while(i > 1) {
    ret *= i--;
    ret %= MOD;
  }
  cout << ret << "\n";
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

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
typedef pair<unsigned char, unsigned char> pcc;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> matrix;

void die() {
  cout << "Impossible\n";
  exit(0);
}

void solve() {
  int n;
  cin >> n;
  vector<int> v;
  v.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  if(2*v[0] < v[n-1]) die();
  int diam = v[n-1];
  for(int a = 0; a <= diam; a++) {
    int b = diam - a;
    int want = max(a, b);
    bool found = false;
    for(int i = 0; !found && i < v.size(); i++) {
      if(v[i] == want) {
        v.erase(v.begin() + i);
        found = true;
      }
    }
    if(!found) die();
  }
  while(v.size()) {
    bool found = false;
    for(int a = 0; a <= diam; a++) {
      int b = diam - a;
      int now = max(a+1, b+1);
      if(now == v.back()) found = true;
    }
    if(found) v.pop_back();
    else die();
  }
  cout << "Possible\n";
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

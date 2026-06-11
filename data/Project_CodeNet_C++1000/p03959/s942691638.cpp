#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;

int main() {
  //
  map<int, ll> unique_height;
  ll n;
  cin>>n;
  vl t(n),a(n);
  rep(i,n) cin>>t[i];
  rep(i,n) cin>>a[i];
  if (n == 1 && t[0] != a[0]) {
    cout << 0 << endl;
    return 0;
  }
  unique_height[0] = t[0];
  unique_height[n-1] = a[n-1];
  REP(i,1,n) {
    if (t[i] > t[i-1]) {
      unique_height[i] = t[i];
      if (t[i] > a[i]) {
        cout << 0 << endl;
        return 0;
      }
    }
  }
  for (int i = n-2; i >= 0; i--) {
    if (a[i] > a[i+1]) {
      if (unique_height.find(i) == unique_height.end()) {
        unique_height[i] = a[i];
        if (a[i] > t[i]) {
          cout << 0 << endl;
          return 0;
        }
      } else {
        if (a[i] != unique_height[i]) {
          cout << 0 << endl;
          return 0;
        }
      }
    }
  }

  ll ans = 1;
  rep(i, n) {
    if (unique_height.find(i) == unique_height.end()) {
      ans = ans * min(t[i], a[i]) % MOD;
    }
  }
  cout << ans << endl;
  return 0;
}

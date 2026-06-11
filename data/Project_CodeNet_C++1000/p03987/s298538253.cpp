
#include <algorithm>
#include <chrono>
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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
int main() {
  //
  ll n;
  cin >> n;
  map<ll, ll> mp;
  rep(i, n) {
    ll a;
    cin >> a;
    mp[a] = i;
  }
  set<ll> s1;
  set<ll, greater<ll>> s2;
  ll ans = 0;
  for (auto& x : mp) {
    ll a = x.first;
    ll i = x.second;
    s1.insert(i);
    s2.insert(i);
    set<ll>::iterator rit = s2.find(i);
    set<ll>::iterator it = s1.find(i);
    ll c1 = 0, c2 = 0;
    rit++;
    it++;
    if (rit == s2.end()) {
      c1 = i + 1;
    } else {
      c1 = i - *rit;
    }
    if (it == s1.end()) {
      c2 = n - i;
    } else {
      c2 = *it - i;
    }
    ans += a * c1 * c2;
  }
  cout << ans << endl;
  return 0;
}
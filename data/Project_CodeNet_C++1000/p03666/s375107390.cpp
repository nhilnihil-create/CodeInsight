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

int n;

void solve() {
  ll a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  n--;
  bool can = false;
  for(int inc = 0; inc <= n; inc++) {
    ll smallest = a + c * inc - d * (n - inc);
    ll largest = a + d * inc - c * (n - inc);
    can |= smallest <= b && b <= largest;
  }
  if(can) cout << "YES\n";
  else cout << "NO\n";
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

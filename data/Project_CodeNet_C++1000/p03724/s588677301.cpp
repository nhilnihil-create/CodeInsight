#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(20) << fixed;

  int n, m;
  cin >> n >> m;

  map<int, int> mp;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    mp[a]++; mp[b]++;
  }

  for (std::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    int value = (*it).second;
    if (value&1) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

  return 0;
}
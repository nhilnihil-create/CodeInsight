#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  REP(i, m) {
    int a, b;
    cin >> a >> b;
    mp[a]++;
    mp[b]++;
  }
  for (auto v : mp) {
    if (v.second % 2 != 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
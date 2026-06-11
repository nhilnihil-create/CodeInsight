#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string w; cin >> w;
  map<char,int> m;
  for (auto wi : w) {
    m[wi]++;
  }
  string ans = "Yes";
  for (auto mi : m) {
    if (mi.second % 2 == 1) {
      ans = "No";
    }
  }
  cout << ans << endl;
  return 0;
}
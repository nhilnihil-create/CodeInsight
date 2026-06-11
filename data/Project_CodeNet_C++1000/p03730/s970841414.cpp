#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c; cin >> a >> b >> c;
  string ans = "NO";
  int i = 1;
  while (a*i % b != 0) {
    if (a*i % b == c) {
      ans = "YES";
      break;
    }
    i++;
  }
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string a, b; cin >> a >> b;
  int an = a.size(), bn = b.size();
  string ans = "EQUAL";
  if (an > bn) {
    ans = "GREATER";
  } else if (an < bn) {
    ans = "LESS";
  } else if (an == bn) {
    rep(i,an) {
      if (a[i] > b[i]) {
        ans = "GREATER"; break;
      } else if (a[i] < b[i]) {
        ans = "LESS"; break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
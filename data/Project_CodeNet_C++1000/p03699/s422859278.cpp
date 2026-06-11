#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> s(n);
  int sum = 0, ans = 0;
  rep(i,n) {
    cin >> s[i];
    sum += s[i];
  }
  if (sum % 10 != 0) {
    ans = sum;
  } else {
    sort(s.begin(),s.end());
    int cs=0;
    rep(i,n) {
      if (s[i] % 10 != 0) {
        ans = sum - s[i];
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
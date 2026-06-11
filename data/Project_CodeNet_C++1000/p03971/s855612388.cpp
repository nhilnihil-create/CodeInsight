#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, a, b; cin >> n >> a >> b;
  string s; cin >> s;
  int border = a+b;
  int out = 1, pass = 0;
  rep(i,s.size()) {
    if (pass < border) {
      if (s[i] == 'a') {
        cout << "Yes" << endl;
        pass++;
        continue;
      }
      if (s[i] == 'b' && b >= out) {
        cout << "Yes" << endl;
        pass++; out++;
        continue;
      }
    }
    cout << "No" << endl;
  }
  return 0;
}
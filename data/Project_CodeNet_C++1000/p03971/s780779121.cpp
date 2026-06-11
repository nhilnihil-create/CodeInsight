#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, a, b; cin >> n >> a >> b;
  string s; cin >> s;
  string ans = "Yes";
  int border = a+b;
  int out = 1, pass = 0;
  rep(i,s.size()) {
    if (s[i] == 'c') {
      cout << "No" << endl;
      continue;
    }
    if (pass < border) {
      if (s[i] == 'a') {
        cout << "Yes" << endl;
        pass++;
      }
      if (s[i] == 'b') {
        if (b >= out) {
          cout << "Yes" << endl;
          pass++;
          out++;
        } else {
          cout << "No" << endl;
        }
      }
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
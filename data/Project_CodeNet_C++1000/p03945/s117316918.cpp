#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; cin >> s;
  int sn = s.size();
  int cnt = 0;
  rep(i,sn) {
    cnt++;
    while (i < sn && s[i] == s[i+1]) i++;
  }
  cout << cnt - 1 << endl;
  return 0;
}
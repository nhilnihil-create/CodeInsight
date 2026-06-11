#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string S;
  cin >> S;
  int N = S.size();
  int co = 0;
  int ans = 0;
  rep(i, N) {
    rep(j, N) {
      if(S.at(i) == S.at(j)) {
        co++;
      }
    }
    if(co > 1) {
      ans++;
      break;
    }
    co = 0;
  }
  if(ans == 0) {
    cout << "yes" << endl;
  }
  else {
    cout << "no" << endl;
  }
}
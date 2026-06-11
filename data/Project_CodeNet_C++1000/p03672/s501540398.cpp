#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string S;
  cin >> S;
  int N = S.size() / 2;
  int co = 0;
  int ans = 0;
  rep(i, N - 1) {
    rep(j, i) {
      if(S.at(j - 1) == S.at(j - 1 + i)) {
        co++;
      }
    }
    if(co == i) {
      ans = i * 2;
    }
    co = 0;
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N;
  string S;
  cin >> N >> S;
  int X, co;
  X = co = 0;
  rep(i, N) {
    if(S.at(i) == 'D') {
      X--;
    }
    else {
      X++;
    }
    co = max(X, co);
  }
  cout << co;
}
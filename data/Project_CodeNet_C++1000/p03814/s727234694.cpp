#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string A;
  cin >> A;
  int X = A.size();
  int M, N;
  M = N = 0;
  rep(i, X) {
    if(A.at(i) == 'A') {
      M = i;
      break;
    }
  }
  for(int i = X - 1; i >= 0; i--) {
    if(A.at(i) == 'Z') {
      N = i;
      break;
    }
  }
  cout << N - M + 1 << endl;
}

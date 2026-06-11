#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int P = A % B;
  int X = P;
  int co = 2;
  int tf;
  while(true) {
    if(X == C) {
      tf = 0;
      break;
    }
    X = A * co % B;
    if(X == P) {
      tf = 1;
      break;
    }
    co++;
  }
  if(tf == 0) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
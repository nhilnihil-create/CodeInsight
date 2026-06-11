#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string A, B;
  cin >> A >> B;
  int X = A.size();
  int Y = B.size();
  rep(i, Y) {
    cout << A.at(i) << B.at(i);
  }
  if(X > Y) {
    cout << A.at(X - 1);
  }
}
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
  cout << S.at(0) << N - 2 << S.at(N - 1) << endl;
}
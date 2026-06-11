#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> vec(N, vector<int>(2));
  rep(i, N) {
    vec.at(i).at(0) = i + 1;
    vec.at(i).at(1) = 0;
  }
  int X;
  rep(i, M) {
    cin >> X;
    vec.at(X - 1).at(1) += 1;
    cin >> X;
    vec.at(X - 1).at(1) += 1;
  }
  rep(i, N) {
    cout << vec.at(i).at(1) << endl;
  }
}
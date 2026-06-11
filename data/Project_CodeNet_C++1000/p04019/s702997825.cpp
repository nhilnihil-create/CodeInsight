#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  string T;
  cin >> T;
  bool N = false, W = false, E = false, S = false;
  bool X = false, Y = false;
  for (auto c : T) {
    if (c == 'N') {
      N = true;
      Y = true;
    } else if (c == 'S') {
      S = true;
      Y = true;
    } else if (c == 'W') {
      W = true;
      X = true;
    } else {
      E = true;
      X = true;
    }
  }
  if (Y)
    if (!N || !S) {
      cout << "No" << endl;
      return 0;
    }
  if (X)
    if (!E || !W) {
      cout << "No" << endl;
      return 0;
    }
  cout << "Yes" << endl;
}
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N;
  cin >> N;
  vector<int> PM(N);
  int sum = 0;
  rep(i, N) {
    cin >> PM.at(i);
    sum += PM.at(i);
  }
  int M;
  cin >> M;
  int P, X;
  rep(i, M) {
    cin >> P >> X;
    cout << sum - PM.at(P - 1) + X << endl;
  }
}
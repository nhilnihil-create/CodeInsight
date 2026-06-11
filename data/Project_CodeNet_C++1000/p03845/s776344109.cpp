#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int N, M;
  vector<int> T, P, X;
  cin >> N;
  rep(i, N) {
    int x;
    cin >> x;
    T.push_back(x);
  }
  cin >> M;
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    P.push_back(x - 1);
    X.push_back(y);
  }
  rep(i, M) {
    int sum = 0;
    rep(j, N) {
      if (j == P[i]) {
        sum += X[i];
      }
      else {
        sum += T[j];
      }
    }
    cout << sum << endl;
  }
  return 0;
}

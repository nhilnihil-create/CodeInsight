#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, X;
  cin >> N >> A;
  vector<long> DP(5001);
  DP.at(2500) = 1;
  while (cin >> X) {
    X -= A;
    if (X > 0) for (int i = 5000; i >= X; i--) DP.at(i) += DP.at(i - X);
    else for (int i = 0; i - X <= 5000; i++) DP.at(i) += DP.at(i - X);
  }
  cout << DP.at(2500) - 1 << "\n";
}
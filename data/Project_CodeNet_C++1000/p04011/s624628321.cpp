#include<bits/stdc++.h>

using namespace std;

int main() {
  int N, K, X, Y, result;
  cin >> N >> K >> X >> Y;
  if (N <= K) {
    result = N * X;
  } else {
    result = K * X + (N-K) * Y;
  }
  cout << result << endl;
  return 0;
}
  
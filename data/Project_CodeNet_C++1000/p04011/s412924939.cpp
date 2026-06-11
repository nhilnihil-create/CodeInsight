#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, X, Y;
  cin >> N >> K >> X >> Y;
  int sum;
  if (N<=K) {
    sum = X*N;
  }
  else{
    sum = X*K + Y*(N-K);
  }
  cout << sum <<endl;
}
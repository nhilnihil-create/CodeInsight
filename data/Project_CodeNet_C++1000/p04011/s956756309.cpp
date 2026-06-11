#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, X, Y, price = 0;
  cin >> N >> K >> X >> Y;

  for (int i = 0; i < N; i++) {
    if (i < K) price += X;
    else price += Y;
  }
  cout << price << endl;
}
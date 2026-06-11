#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, a, b;
  cin >> N >> K;
  b = 0;
  
  for (int i = 0; i < N; i++) {
    cin >> a;
    if (a < K - a) {
      b += 2 * a;
    }
    else {
      b += 2 * (K - a);
    }
  }
  
  cout << b << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, A;
  cin >> N >> K;
  A = 0;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if (x <= (K - x)) {
      A += (x * 2);
    }
    else {
      A += ((K - x) * 2);
    }
  }
  cout << A << endl;
}

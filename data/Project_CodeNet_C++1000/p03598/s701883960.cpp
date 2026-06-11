#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  
  int sum = 0;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    int A = x * 2;
    int B = (K - x) * 2;
    if (A < B) {
      sum += A;
    } else {
      sum += B;
    }
  }
  cout << sum << endl;
}

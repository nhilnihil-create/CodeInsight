#include <bits/stdc++.h>
using namespace std;

int main() {
  int a = 0, x, c = 1, N, K;
  cin >> N >> K;
  for (int j = 0; j < N; j++){
    cin >> x;
    if (x < abs(K - x)){
      a += 2 * x;
    }
    else {
      a += 2 * abs(K - x);
    }
  }
  cout << a << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int d = 0;
  int N, K, x;
  cin >> N >> K;
  
  for(int i = 0; i < N; i++){
    cin >> x;
    int kx = K - x;
    if (x < kx)
      d += x * 2;
    else d += kx * 2;
  }
  cout << d << endl;
}
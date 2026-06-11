#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  
  int d = 0, x;
  for (int i=0; i<N; i++) {
    cin >> x;
    if (K-x >= 0) {
      if (x <= K-x) {
        d += x*2;
      }
      else {
        d += (K-x)*2;
      }
    }
    else {
      if (x <= x-K) {
        d += x*2;
      }
      else {
        d += (x-K)*2;
      }
    }
  }
  
  cout << d << endl;
}
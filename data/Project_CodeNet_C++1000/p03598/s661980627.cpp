#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  
  int total = 0;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    
    int length;
    if (x < (K - x)) {
      length = 2 * x;
    }
    else {
      length = 2 * (K - x);
    }
    total += length;
  }
  cout << total << endl;
}
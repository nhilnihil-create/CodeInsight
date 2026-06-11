#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, K;
  cin >> N >> K;

  int x;
  int sum = 0;
  
  rep(cnt, N) {
    cin >> x;
    if ( x < K-x ) {
      sum += x * 2;
    } else {
      sum += (K - x) * 2;
    }
  }
  cout << sum;  
}
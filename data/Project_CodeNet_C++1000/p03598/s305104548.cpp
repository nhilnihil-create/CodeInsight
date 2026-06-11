#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int ans = 0;
  
  for(int i=0; i<N; i++) {
    int x;
    cin >> x;
    if(x <= K) {
      ans += min(x, K-x);
    }
    else {
      ans += min(x, x-K);
    }
  }
  
  cout << 2 * ans << endl;
}
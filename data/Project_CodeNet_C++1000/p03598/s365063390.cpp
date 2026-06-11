#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K,x;
  cin >> N >> K;
  int sum = 0;
  
  for (int i = 0; i < N; i++) {
    cin >> x;
    if (x > K/2) {
      if (x > K) 
        sum += 2*(x-K);
      else 
        sum += 2*(K-x);
    }
    else 
      sum += 2*x;
  }
  cout << sum << endl;
}

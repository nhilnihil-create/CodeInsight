#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, a, sum;
  cin >> N >> K;
  a = K / 2;
  for(; N > 0; N--) {
    int x;
    cin >> x;
    if(x > a) {
      sum += K - x;
    }
    else {
      sum += x;
    }
  }
  
  cout << sum * 2 << endl;
}
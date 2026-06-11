#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  // ここにプログラムを追記
  int x, min = 0;
  for(int i=0; i<N; i++) {
    cin >> x;
    
    if(K>x) {
      if(x-0 < K-x) {
        min += x-0;
      }
      else {
      	min += K-x;
      }
    }
    else {
      if(x-0 < x-K) {
        min += x-0;
      }
      else {
      	min += x-K;
      }
    }
  }
  cout << min*2 << endl;
}
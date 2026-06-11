#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int N, K;
  cin >> N >> K;
  
  // 計算をしていく
  int x = 0;
  int sumKyori = 0;
  rep(i, N) {
    cin >> x;
    
    if (x < K - x) {
      sumKyori += x * 2;
    }
    else {
      sumKyori += (K - x) * 2;
    }
  }
 
  // 計算結果を出力
  cout << sumKyori << endl;
}
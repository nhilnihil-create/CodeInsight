#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K, x;
  cin >> N >> K;
  int total = 0; // 総移動距離
  
  for (int i = 0; i < N; i++) {
    cin >> x;
    if (abs(x) < abs(K - x)) total += x * 2; // type B ロボの方が遠い時
    else total += (K - x) * 2;
  }
  cout << total << endl;
}
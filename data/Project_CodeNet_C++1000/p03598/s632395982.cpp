#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  int S = 0;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if (x <= K / 2) { S += 2 * x;}
    else { S += 2 * (K - x);}
  }
  cout << S << endl;
}
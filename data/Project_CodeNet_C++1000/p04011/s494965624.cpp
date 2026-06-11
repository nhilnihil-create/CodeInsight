#include <bits/stdc++.h>
using namespace std;



void solve() {
  int N, K, X, Y;
  cin >> N >> K >> X >> Y;
  int a = min(K, N);
  int b = N-K;
  if(b < 0) b = 0;
  cout << a*X + b*Y;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}

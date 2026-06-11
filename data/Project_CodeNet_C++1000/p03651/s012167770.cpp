#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int A;
  cin >> A;
  int G = A, M = A;
  for (int i = 1; i < N; i++) {
    int a;
    cin >> a;
    G = __gcd(a, G);
    M = max(a, M);
  }
  if (K <= M && K % G == 0) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N;
  int T[N], sum = 0, P, X;
  for (int i = 0; i < N; i++) {
    cin >> T[i];
    sum += T[i];
  }
  for (cin >> M; M; M--) {
    cin >> P >> X;
    cout << sum-T[P-1]+X << endl;
  }
}
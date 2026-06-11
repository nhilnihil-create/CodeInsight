#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int M;

  cin >> N;
  int T[N];
  for (int i = 0; i < N; i++) cin >> T[i];
  cin >> M;
  int P[M];
  int X[M];
  for (int i = 0; i < M; i++) {
    cin >> P[i] >> X[i];
  }

  int sum = 0;
  for (int i = 0; i < N; i++) sum += T[i];

  for (int i = 0; i < M; i++){
    cout << sum - T[ P[i] - 1] + X[i] <<endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> T(N);
  long long int sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> T[i];
    sum += T[i];
  }
  int M;
  cin >> M;
  vector<int> P(M), X(M);
  for(int i = 0; i < M; i++) {
    cin >> P[i] >> X[i];
    int p = P[i] - 1;
    cout << sum - T[p] + X[i] << endl;
  }
  return 0;
}
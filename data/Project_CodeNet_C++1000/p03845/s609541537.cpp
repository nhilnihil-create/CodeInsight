#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> T(N);
  for (int i = 0; i < N; i++) cin >> T.at(i);
  long sum = accumulate(T.begin(), T.end(), 0L);
  int M;
  cin >> M;
  while (M--) {
    int P, X;
    cin >> P >> X;
    P--;
    cout << sum - T.at(P) + X << "\n";
  }
}
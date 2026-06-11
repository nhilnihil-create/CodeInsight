#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    A.at(i)--;
  }
  int now = 0;
  for (int i = 1; i < N * 2; i++) {
    now = A.at(now);
    if (now == 1) return cout << i << "\n", 0;
  }
  cout << -1 << "\n";
}
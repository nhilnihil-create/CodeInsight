#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector A(N, 0);
  for (int i = 0, a; cin >> a; i++) A.at(i) = --a;
  int cnt = 0;
  for (int i = 0; i < N; i++) if (A.at(A.at(i)) == i) cnt++;
  cout << cnt / 2 << "\n";
}
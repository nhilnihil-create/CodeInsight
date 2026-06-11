#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(N);
  while (cin >> M) a.at(M - 1)++;
  for (M = N; M--; cout << a.at(N - M - 1) << endl);
}
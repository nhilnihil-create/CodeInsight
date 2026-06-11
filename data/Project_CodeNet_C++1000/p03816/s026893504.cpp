#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  map<int, int> M;
  for (int i = 0; i < N; i++) {
    int A; cin >> A;
    if (M.count(A)) M[A]++;
    else M[A] = 1;
  }
  int cnt = 0;
  for (auto p : M) {
    if (p.second % 2 == 0) cnt++;
  }
  if (cnt % 2 == 1) cout << M.size() - 1 << endl;
  else cout << M.size() << endl;
}
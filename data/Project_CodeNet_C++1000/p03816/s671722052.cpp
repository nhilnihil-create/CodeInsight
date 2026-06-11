#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  rep(i, N) cin >> A[i];

  sort(A.begin(), A.end());
  A.push_back(0); // dummy

  int cnt = 0;
  int pos = 0;
  for (int i = 1; i <= N; ++i) {
    if (A[i] == A[i - 1])
      continue;
    ++cnt;
    pos = i;
  }

  if (cnt % 2 == 0)
    cout << cnt - 1 << endl;
  else
    cout << cnt << endl;
}
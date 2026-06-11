#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, K;
  cin >> N >> K;
  long long res = 0;
  for (int i = 0; i < N; ++i) {
    long long A;
    cin >> A;
    res += min(A, K-A) * 2;
  }
  cout << res << endl;
}
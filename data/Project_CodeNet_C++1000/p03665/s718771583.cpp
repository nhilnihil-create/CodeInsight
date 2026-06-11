#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, P;
  cin >> N >> P;

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a % 2 == 0) cnt++;
  }

  if (cnt == N && P == 0) {
    cout << (long long)pow(2, N) << endl;
    return 0;
  } else if (cnt == N && P == 1) {
    cout << 0 << endl;
    return 0;
  }

  cout << (long long)pow(2, N - 1) << endl;
}
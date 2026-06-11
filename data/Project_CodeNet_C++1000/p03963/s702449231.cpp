#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, K;
  cin >> N >> K;

  long long color = K;
  for (int i = 0; i < N - 1; ++i) {
    color *= (K - 1);
  }

  cout << color << endl;
  return 0;
}

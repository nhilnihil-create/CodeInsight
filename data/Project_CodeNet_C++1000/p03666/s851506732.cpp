#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  for (int i = 0; i < N; i++) {
    if (C * i - D * (N - 1 - i) <= B - A && B - A <= -C * (N - 1 - i) + D * i) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll K;
const ll N = 50;

int main() {
  cin >> K;
  cout << N << endl;
  for (ll i = 0; i < N; ++i) {
    cout << (i == 0 ? "" : " ")
         << N - 1 + K / N - K % N + (i < K % N ? N + 1 : 0);
  }
  cout << endl;
  return 0;
}

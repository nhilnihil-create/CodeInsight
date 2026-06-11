#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ll K;
  cin >> K;
  const int N = 50;
  cout << N << endl;
  for (int i = 0; i < N; i++) {
    ll s = K / N + (i < K % N);
    ll a = N - 1 + s * N - (K - s);
    cout << a << " ";
  }
  cout << endl;
  return 0;
}

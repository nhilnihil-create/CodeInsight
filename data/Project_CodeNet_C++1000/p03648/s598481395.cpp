#include <iostream>
using namespace std;

const long long N = 50;

int main() {
  long long K;
  cin >> K;

  long long ans[N];
  for (long long i = 0; i < N; i++) {
    ans[i] = i + (K - 1) / N;
  }

  for (long long i = N - (K - 1) % N - 1; i < N; i++) {
    ans[i]++;
  }

  cout << N << endl;
  for (long long i = 0; i < N - 1; i++) {
    cout << ans[i] << ' ';
  }
  cout << ans[N - 1] << endl;

  return 0;
}

#include <iostream>

using namespace std;

const int MOD = 1000000007;

int cnt[100005];

long long pow(long long x, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n % 2 == 1) res = res * x % MOD;
    x = x * x % MOD;
    n = n / 2;
  }
  return res;
}


int main() {
  int N;
  cin >> N;

  int d = (N - 1) % 2;
  for (int i = 0; i < N; ++i) {
    int A;
    cin >> A;
    cnt[A]++;

    if (A % 2 != d || cnt[A] > 2 || A == 0 && cnt[0] > 1) {
      cout << 0 << endl;
      return 0;
    }
  }

  cout << pow(2, N / 2) << endl;
}

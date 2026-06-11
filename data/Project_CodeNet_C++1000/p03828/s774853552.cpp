#include <bits/stdc++.h>
using namespace std;

vector<bool> is_prime;

void eratos(int N) {
  is_prime[0] = false, is_prime[1] = false;
  for (int i = 2; i * i <= N; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
  int N;
  cin >> N;

  is_prime.resize(N + 1, true);
  eratos(N);

  map<int, int> m;
  for (int i = 2; i <= N; ++i) {
    if (is_prime[i]) {
      for (int j = i; j <= N; j *= i) {
        m[i] += N / j;
      }
    }
  }

  long long ans = 1;
  for (auto i : m) {
    ans = ans * (i.second + 1) % 1000000007;
  }

  cout << ans << endl;
}
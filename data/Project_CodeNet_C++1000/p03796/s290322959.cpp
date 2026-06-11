#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 階乗 (mod 対応版)
ll factorial_mod(int n, int m) {
  long long ret = 1;
  for (int i = n; i > 0; --i) ret = (ret * i) % m;
  return ret;
}

int main() {
  int N;
  cin >> N;

  long long power = factorial_mod(N, 1000000007);

  cout << power << endl;
}
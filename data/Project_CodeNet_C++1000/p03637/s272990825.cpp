#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long int64;
int MOD = 1e9 + 7;

int64 inv(int64 a, int64 mod) {
  a %= mod;
  int64 v[] = { 0, 1, mod };
  int64 u[] = { 1, 0, a };
  while (v[2] != 1) {
    if (v[2] < u[2]) {
      int64 tmp[] = { v[0], v[1], v[2] };
      v[0] = u[0]; v[1] = u[1]; v[2] = u[2];
      u[0] = tmp[0]; u[1] = tmp[1]; u[2] = tmp[2];
      continue;
    }
    int64 coe = v[2] / u[2];
    for (int i = 0; i < 3; ++i) v[i] = v[i] - u[i] * coe;
  }
  return v[0] < 0 ? v[0] + mod : v[0];
}

int64 pow(int64 a, int64 p, int64 mod) {
  a %= mod;
  int64 ret = a;
  while (p > 1) {
    if (p % 2) {
      ret = (ret * ret) % mod;
      ret = (ret * a) % mod;
    } else {
      ret = (ret * ret) % mod;
    }
    p /= 2;
  }
  return ret;
}

int main() {
  //cout << fixed << setprecision(15);
  int N;
  cin >> N;
  int cnt1 = 0;
  int cnt2 = 0;
  int cnt4 = 0;
  int tmp;
  rep(i, N) {
    cin >> tmp;
    if (tmp % 4 == 0) ++cnt4;
    else if (tmp % 2 == 0) ++cnt2;
    else  ++cnt1;
  }

  if (cnt2 == 0 && (cnt1 <= cnt4+1)) cout << "Yes" << "\n";
  else if ((cnt1 <= cnt4)) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}

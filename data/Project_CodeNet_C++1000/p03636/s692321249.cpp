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
  string S;
  cin >> S;
  cout << S[0] << S.size()-2 << S[S.size()-1] << "\n";
  return 0;
}

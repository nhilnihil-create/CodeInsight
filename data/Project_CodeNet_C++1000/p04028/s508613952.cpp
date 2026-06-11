#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int n;
string s;
int dp[5001][5001];

long powmod(long b, long e) {
  if (e == 0) return 1;
  if (e & 1) return powmod(b, e - 1) * b % mod;
  long t = powmod(b, e / 2);
  return t * t % mod;
}

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

int main() {
  cin >> n >> s;
  
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      add(dp[i + 1][max(0, j - 1)], dp[i][j]);
      add(dp[i + 1][j + 1], dp[i][j]);
      add(dp[i + 1][j + 1], dp[i][j]);
    }
  }
  cout << dp[n][s.size()] * powmod(500000004, s.size()) % mod << endl;
}
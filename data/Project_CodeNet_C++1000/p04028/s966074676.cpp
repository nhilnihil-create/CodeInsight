#include <iostream>

using namespace std;

const int MOD = 1000000007;

typedef long long llong;

struct modint {
  llong val;

  modint () {
    val = 0;
  }

  modint (llong _val) {
    val = _val % MOD;
  }
};

modint operator+ (modint p, modint q) {
  return modint((p.val + q.val) % MOD);
}

modint operator- (modint p, modint q) {
  return modint((p.val - q.val + MOD) % MOD);
}

modint operator- (modint p) {
  return modint(0) - p;
}

modint operator* (modint p, modint q) {
  return modint((p.val * q.val) % MOD);
}

modint operator^ (modint p, int q) {
  modint pows [30];

  pows[0] = p;
  for (int i = 1; i < 30; i++) {
    pows[i] = pows[i - 1] * pows[i - 1];
  }

  modint ans (1);
  for (int i = 0; i < 30; i++) {
    if (q & 1 << i) {
      ans = ans * pows[i];
    }
  }

  return ans;
}

modint inv (modint p) {
  return p ^ (MOD - 2);
}

modint operator/ (modint p, modint q) {
  return p * (q ^ (MOD - 2));
}

const int MAX_N = 5005;

modint dp [MAX_N][MAX_N]; /* # of ways to get a string of length j with i moves */

int main () {
  dp[0][0] = modint(1);
  for (int i = 1; i < MAX_N; i++) {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    for (int j = 1; j < MAX_N - 1; j++) {
      dp[i][j] = modint(2) * dp[i - 1][j - 1] + dp[i - 1][j + 1];
    }
  }
  
  int length;
  string str;
  cin >> length >> str;

  cout << (dp[length][(int) str.size()] / (modint(2) ^ (int) str.size())).val << endl;
}

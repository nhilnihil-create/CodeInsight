#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
int D[1000010];
ll S[1000010];

int main() {
  int n; scanf("%d", &n);
  D[0] = 1; D[1] = n;
  S[0] = 1; S[1] = n + 1;
  for(int i=2;i<=n;i++){
    D[i] = ((ll)(n-1) * (i-2) + (ll)(n - i + 1) * n + D[i-1] + (i>=3?S[i-3]:0)) % MOD;
    S[i] = (S[i-1] + D[i]) % MOD;
  }
  printf("%d\n", D[n]);
  return 0;
}

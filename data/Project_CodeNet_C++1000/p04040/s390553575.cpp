#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long LL;
int H, W, A, B;
LL dp[200001] = {1,1,};
int saved = 1;
const int MOD = 1e9+7;

LL fact(int x){
  for(int i = saved+1; i <= x; i++)
    dp[i] = (dp[i-1] * i) % MOD;
  saved = max(x, saved);
  return dp[x];
}

LL pow(LL b, LL e) {
  LL ans = 1;
  while(e) {
    if(e&1) ans = (ans*b)%MOD;
    b = (b*b)%MOD;
    e /= 2;
  }
  return ans;
}

LL comb(int n, int r) {
  if(n <= r || r == 0) return 1;
  LL a = fact(n);
  LL b = (fact(r) * fact(n-r)) % MOD;
  LL inv = pow(b, MOD-2);
  return (a * inv) % MOD;
}

int main() {
  cin >> H >> W >> A >> B;
  int n = min(H-A, W-B);
  int a = H-A-1;
  int b = B;
  int c = A;
  int d = W-B-1;
  LL ans = 0;
  for(int i = 0; i < n; i++)
    ans = (ans + (comb(a-i+b+i, a-i) * comb(c+i+d-i, c+i)) % MOD) % MOD;
  cout << ans;
}


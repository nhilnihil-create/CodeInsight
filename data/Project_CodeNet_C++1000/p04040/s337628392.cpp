#include <iostream>
#include <vector>
#define int long long
using namespace std;

int mod = 1000000007;
vector<int> K(200100);

void prepare() {
  K[0] = 1;
  for (int i = 1; i < K.size(); ++i) {
    K[i] = K[i - 1] * i % mod;
  }
  return;
}

int pow(int a, int b) {
  if (b == 1) return a;
  int ans = pow(a, b / 2);
  if (b % 2 == 0) return ans * ans % mod;
  else return ans * ans % mod * a % mod;
}

int com(int m, int n) {
  int ans = K[m];
  ans *= pow(K[n], mod - 2);
  ans %= mod;
  ans *= pow(K[m - n], mod - 2);
  ans %= mod;
  return ans;
}

int route(int si, int sj, int gi, int gj) {
  int x = gi - si;
  int y = gj - sj;
  return com(x + y, x);
}

signed main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  
  prepare();
  int ans = route(1, 1, H, W);
  int C = H - A;
  for (int i = 1; i <= B; ++i) {
    int a = route(1, 1, C, i);
    a *= route(C + 1, i, H, W);
    a %= mod;
    ans += (mod - a);
    ans %= mod;
  }
  
  cout << ans << endl;
  return 0;
}
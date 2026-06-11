#include <cstdio>
#include <cstdint>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  constexpr intmax_t mod=1e9+7;

  intmax_t res_x=0;
  for (int i=0; i<n; ++i) {
    intmax_t x;
    scanf("%jd", &x);
    res_x = (res_x + (2*i-n+1)*x) % mod;
  }

  intmax_t res_y=0;
  for (int j=0; j<m; ++j) {
    intmax_t y;
    scanf("%jd", &y);
    res_y = (res_y + (2*j-m+1)*y) % mod;
  }

  printf("%jd\n", res_x*res_y%mod);
}

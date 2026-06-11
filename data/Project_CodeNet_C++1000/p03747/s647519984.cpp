#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N; double L, T; std::cin >> N >> L >> T;
  std::vector<double> x(N), v(N), a(N);
  T -= 1.0/16.0;
  for(int i = 0; i < N; ++i) {
    int X, W; std::cin >> X >> W;
    x[i] = X;
    if(W == 1) {
      v[i] = 1.0;
      a[i] = std::fmod(x[i] + T, L);
    } else {
      v[i] = -1.0;
      a[i] = std::fmod(x[i] - T, L);
      a[i] = std::fmod(a[i]+L, L);
    }
  }
  double p0 = a[0];
  std::sort(a.begin(), a.end());
  int n0 = 0;
  if(v[0] > 0) {
    for(int i = 1; i < N; ++i) if(v[0]+v[i] == 0) {
      if(T+T > x[i]-x[0]) {
        double t = T+T-(x[i]-x[0]);
        (n0 += 1+int(t/L)) %= N;
      }
    }
  } else for(int i = 1; i < N; ++i) if(v[0]+v[i] == 0) {
    if(T+T > L - (x[i]-x[0])) {
      double t = T+T-(L-(x[i]-x[0]));
      (n0 -= 1+int(t/L)) %= N;
      (n0 += N) %= N;
    }
  }
  int i0 = std::lower_bound(a.begin(), a.end(), p0) - a.begin();
  (i0 += N-n0) %= N;
  for(int i = 0; i < N; ++i) {
    std::cout << int(a[(i0+i)%N]+1.0/8.0)%(int)L << "\n";
  }
  return 0;
}

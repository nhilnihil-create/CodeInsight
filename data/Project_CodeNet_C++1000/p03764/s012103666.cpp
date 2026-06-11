#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

typedef long long ll;

const ll MOD = 1e9 + 7;

int main(int argc, char* argv[])
{
  ll n, m;
  std::cin >> n >> m;
  std::vector< ll > vx;
  std::vector< ll > vy;

  vx.resize(n);
  vy.resize(m);
  //fill(vx.begin(), vx.end(), 0);
  //fill(vy.begin(), vy.end(), 0);

  std::vector< ll >::iterator it;
  for (it = vx.begin(); it != vx.end(); it++) {
    ll idx = std::distance(vx.begin(), it);
    std::cin >> vx[idx];
  }

  for (it = vy.begin(); it != vy.end(); it++) {
    ll idx = std::distance(vy.begin(), it);
    std::cin >> vy[idx];
  }

  std::vector< ll > x_sum(n, 0);
  x_sum[0] = vx[0];
  for (ll i = 1; i < n; i++) {
    x_sum[i] = vx[i] + x_sum[i-1];
  }

  ll XX = 0;
  for (ll i = 0; i < n; i++) {
    XX += x_sum[n-1] - x_sum[i] - vx[i] * (n-i-1);
    XX %= MOD;
  }

  std::vector< ll > y_sum(m, 0);
  y_sum[0] = vy[0];
  for (ll i = 1; i < m; i++) {
    y_sum[i] = vy[i] + y_sum[i-1];
  }

  ll YY = 0;
  for (ll i = 0; i < m; i++) {
    YY += y_sum[m-1] - y_sum[i] - vy[i] * (m-i-1);
    YY %= MOD;
  }
  //std::cout << XX << std::endl;
  //std::cout << YY << std::endl;
  std::cout << (XX * YY) % MOD << std::endl;

  
  return 0;
}


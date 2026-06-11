#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 20000;
int v[1 + nmax];

/*
a1 < a2 < .... < an
b1 > b2 > .... > bn
I can increase all sums except one
ap1 + bp1 < ap2 + bp2 < ... apn + bpn
*/
int a[1 + nmax], b[1 + nmax];
int suma[1 + nmax], sumb[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1; i <= n; i++) {
    suma[v[i] + 1] += (n - i + 1);
    sumb[v[i] - 1] += (n - i + 1);
  }
  for(int i = 1;i <= n; i++)
    suma[i] += suma[i - 1];
  for(int i = n; 1 <= i; i--)
    sumb[i] += sumb[i + 1];
  for(int i = 1;i <= n; i++)
    std::cout << i + suma[i] << " ";
  std::cout << '\n';
  for(int i = 1;i <= n; i++)
    std::cout << n - i + 1 + sumb[i] << " ";
  std::cout << '\n';
  return 0;
}

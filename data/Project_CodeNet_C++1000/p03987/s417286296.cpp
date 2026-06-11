#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[1 + nmax], st[1 + nmax], dr[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  v[0] = v[n + 1] = 0;
  for(int i = 1;i <= n; i++) {
    st[i] = i - 1;
    while(v[i] < v[st[i]])
      st[i] = st[st[i]];
  }
  for(int i = n; 1 <= i; i--) {
    dr[i] = i + 1;
    while(v[i] < v[dr[i]])
      dr[i] = dr[dr[i]];
  }
  ll result = 0;
  for(int i = 1;i <= n; i++)
    result += 1LL * v[i] * (i - st[i]) * (dr[i] - i);
  std::cout << result;
  return 0;
}

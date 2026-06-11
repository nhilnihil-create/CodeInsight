#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[1 + nmax], red[1 + nmax];

int main() {
  int n, q;
  std::cin >> n >> q;
  for(int i = 1;i <= n; i++) 
    v[i] = 1;
  red[1] = 1;
  for(int i = 1;i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    if(1 == red[x]){
      red[y] = 1;
      if(1 == v[x]) 
        red[x] = 0;
    }
    v[x]--;
    v[y]++;
  }
  int result = 0;
  for(int i = 1;i <= n; i++)
    result += red[i];
  std::cout << result;
  return 0;
}

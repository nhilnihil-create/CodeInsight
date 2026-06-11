#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int frec[1 + nmax];
int sol[1 + nmax];

int main() {
  int n, x;
  std::cin >> n >> x;
  if(x == 1 || x == n * 2 - 1)
    std::cout << "No";
  else {
    if(n == 2)
      std::cout << "Yes\n" << 1 << " " << 2 << " " << 3 << '\n';
    else {
      sol[n] = x;
      sol[n - 1] = x - 1;
      sol[n + 1] = x + 1;
      frec[x] = frec[x - 1] = frec[x + 1] = 1;
      if(2 < x) {
        sol[n + 2] = x - 2;
        frec[x - 2] = 1;
      } else {
        sol[n - 2] = x + 2;
        frec[x + 2] = 1;
      }
      int ptr = 1;
      for(int i = 1;i <= 2 * n - 1; i++) {
        if(sol[i] == 0) {
          while(frec[ptr] == 1)
            ptr++;
          sol[i] = ptr;
          frec[ptr] = 1;
        }
      }
      std::cout << "Yes\n";
      for(int i = 1;i <= 2 * n - 1; i++)
        std::cout << sol[i] << '\n';
    }
  }
  return 0;
}

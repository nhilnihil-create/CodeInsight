#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[1 + nmax];

int main() {
  int n, lim;
  std::cin >> n >> lim;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  int id = 0;
  for(int i = 1;i < n; i++) {
    if(lim <= v[i] + v[i + 1])
      id = i;
  }
  if(id == 0)
    std::cout << "Impossible";
  else{
    std::cout << "Possible" << '\n';
    for(int i = 1;i < id; i++)
      std::cout << i << '\n';
   for(int i = n - 1;id < i; i--)
     std::cout << i << '\n';
   std::cout << id;
  }
  return 0;
}

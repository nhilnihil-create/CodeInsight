#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[1 + nmax];

std::map<int,int> mp;

void normalize(int n) {
  std::vector<int> aux;
  for(int i = 1;i <= n; i++)
    aux.push_back(v[i]);
  std::sort(aux.begin(), aux.end());
  for(int i = 0; i < n; i++)
    mp[aux[i]] = 1 + i;
  for(int i = 1; i <= n; i++)
    v[i] = mp[v[i]];
}

int main() {
  int n;
  std::cin >> n;
  int result = 0;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  normalize(n);
  for(int i = 1;i <= n; i += 2)
    if(v[i] % 2 == 0)
      result++;
  std::cout << result;
  return 0;
}

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 1000000002486618624LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cout << std::fixed << std::setprecision(6);

  int N, A[333][333];

  bool M[333][333];

  memset(M, 0xff, sizeof(M));

  std::cin >> N;

  for (int i = 0; i < N; i ++)
    for (int j = 0; j < N; j ++)
      std::cin >> A[i][j];

  for (int i = 0; i < N; i ++)
    for (int j = i + 1; j < N; j ++)
      for (int k = 0; k < N; k ++)
        if (k != i && k != j) {
          int l = A[i][k] + A[k][j];
          
          if (l < A[i][j]) {
            std::cout << -1 << std::endl;

            return 0;
          }
          else if (l == A[i][j]) {
            M[i][j] = M[j][i] = false;
          }
        }

  long long s = 0;

  for (int i = 0; i < N; i ++)
    for (int j = i + 1; j < N; j ++)
      if (M[i][j])
        s += A[i][j];

  std::cout << s << std::endl;

  return 0;
}

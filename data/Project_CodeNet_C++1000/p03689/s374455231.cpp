#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int inf = 1000 * 1000 * 100;

int main()
{
  int N, M, n, m;
  cin >> N >> M >> n >> m;
  if (N % n == 0 && M % m == 0) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int cur = 0;
      if (M % m != 0) {
        if (i % n == 0) {
          if (j % m == 0) cur = inf;
          if ((j + 1) % m == 0) cur = -inf - 1;
        }
      } else {
        if (j % m == 0) {
          if (i % n == 0) cur = inf;
          if ((i + 1) % n == 0) cur = -inf - 1;
        }
      }
      if (j > 0) cout << " ";
      cout << cur;
    }
    cout << endl;
  }
  return 0;
}

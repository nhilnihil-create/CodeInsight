#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <cstdint>
#include <cmath>
#include <bitset>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define N_TIMES(i, n)     for ( uint64_t i = 0;     i <  n; ++i )
#define N_TIMES_REV(i, n) for (  int64_t i = n - 1; i >= 0; --i )

using namespace std;

int main()
{
  uint64_t N, M;
  cin >> N >> M;

  vector<uint64_t> C(N, 0);
  N_TIMES(m, M) {
    uint64_t a, b;
    cin >> a >> b;

    ++C[a - 1];
    ++C[b - 1];
  }

  bool flag = true;
  N_TIMES(n, N) {
    if ((C[n] & 1) == 1) { flag = false; break; }
  }
  cout << (flag ? "YES" : "NO") << endl;

  return 0;
}
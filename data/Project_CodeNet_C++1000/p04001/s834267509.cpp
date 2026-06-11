#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
const int INF = 1e9;
const double EPS = 1e-9;
const ll MOD = 1e9 + 7;

int main()
{
  string S;
  cin >> S;

  ll ans = 0;
  for (int bit = 0; bit < (1 << S.size() - 1); ++bit)
  {
    ll sum = 0, tmp = S[0] - '0';
    for (int i = 0; i < S.size() - 1; ++i)
    {
      if (bit & (1 << i))
      {
        sum += tmp;
        tmp = 0;
      }
      else
      {
        tmp *= 10;
      }
      tmp += S[i + 1] - '0';
    }
    sum += tmp;
    ans += sum;
  }
  cout << ans << endl;

  return 0;
}

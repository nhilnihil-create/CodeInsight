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
  std::string s;
  std::cin >> s;
  long long K;
  scanf("%lld", &K);
  for (int i = 0; i < s.size(); ++i)
  {
    if (s[i] == 'a')
      continue;
    int t = (int)('z' - s[i]) + 1;
    if (t <= K)
    {
      K -= t;
      s[i] = 'a';
    }
  }
  K %= 26;
  int t = (K + (int)(s[s.size() - 1] - 'a')) % 26;
  s[s.size() - 1] = (char)('a' + t);
  cout << s << endl;

  return 0;
}

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <valarray>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <limits>
#include <numeric>
#include <utility>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <regex>
#include <array>
#include <bitset>
#include <complex>
#include <tuple>
#include <random>

using namespace std;
using ll = long long;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

int main()
{
  string s;
  cin >> s;
  int fi = -1, ed = -1;
  for (int i = 0; i < s.size() - 1; ++i)
  {
    if (s[i] == s[i + 1])
      fi = i + 1, ed = i + 2;
  }
  for (int i = 0; i < s.size() - 2; ++i)
  {
    if (s[i] == s[i + 2])
      fi = i + 1, ed = i + 3;
  }
  cout << fi << ' ' << ed << endl;

  return 0;
}

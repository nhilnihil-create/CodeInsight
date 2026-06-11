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

const string YES = "Yes";
const string NO = "No";

int main()
{
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  vector<int> cnt(26, 0);
  for (auto &e : a)
  {
    cin >> e;
    for (auto &t : e)
    {
      cnt[t - 'a']++;
    }
  }
  vector<int> g(3, 0);
  g[0] = (W % 2) * (H % 2);
  g[1] = (H % 2) * (W / 2) + (W % 2) * (H / 2);
  g[2] = (W / 2) * (H / 2);
  for (auto &e : cnt)
  {
    while (e)
    {
      if (e % 4 == 1 || e % 4 == 3)
      {
        e--;
        g[0]--;
      }
      else if (e % 4 == 2 || (e % 4 == 0 && g[2] == 0))
      {
        e -= 2;
        g[1]--;
      }
      else if (e % 4 == 0 && e > 0)
      {
        e -= 4;
        g[2]--;
      }
    }
  }
  if (g[0] == 0 && g[1] == 0 && g[2] == 0)
    cout << YES << endl;
  else
    cout << NO << endl;

  return 0;
}

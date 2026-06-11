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
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  std::vector<long long> x(M);
  std::vector<long long> y(M);
  for (int i = 0; i < M; i++)
  {
    scanf("%lld", &x[i]);
    scanf("%lld", &y[i]);
    x[i]--;
    y[i]--;
  }
  vector<ll> t(N, 1);
  set<ll> st;
  st.insert(0);
  for (int i = 0; i < M; ++i)
  {
    t[x[i]]--;
    t[y[i]]++;
    if (st.find(x[i]) != st.end())
    {
      st.insert(y[i]);
      if (t[x[i]] == 0)
      {
        st.erase(x[i]);
      }
    }
  }
  cout << st.size() << endl;

  return 0;
}

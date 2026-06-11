#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

#include <utility>
#include <list>

#include <cmath>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <complex>
#include <climits>
#include <functional>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

#define debug(x) cerr << #x << " = " << x << " "

int gcd(int x, int y)
{
  return x?gcd(y%x, x):y;
}

int main()
{
  int n; scanf("%d", &n);
  vector<int> v(n);
  for (auto & e : v) scanf("%d", &e);
  int cur = 0;
  for (;; cur ^= 1)
    {
      vector<int> cnt(2, 0);
      vector<int> last(2, -1);
      for (int i = 0; i < v.size(); ++i)
	{
	  int parity = v[i]%2;
	  ++cnt[parity];
	  last[parity] = i;
	}
      if (cnt[0]%2 == 1) 
	{
	  break;
	}
      else if (cnt[1] == 1 && v[last[1]] != 1)
	{
	  --v[last[1]];
	  int g = 0;
	  for (auto e : v) g = gcd(g, e);
	  for (auto &e : v) e /= g;
	}
      else 
	{
	  cur ^= 1;
	  break;
	}
    }
  puts(cur?"Second":"First");
}

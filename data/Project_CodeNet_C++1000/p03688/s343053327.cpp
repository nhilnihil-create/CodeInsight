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
#define mp make_pair
#define pb push_back

#define debug(x) cerr << #x << " = " << x << " "
map<int, int> cnt;
int n;
bool ans()
{
  if (cnt.size() > 2) return false;
  if (cnt.size() == 1) return cnt.begin()->first == n-1 || 2 * (cnt.begin()->first) <= n;
  int mini = cnt.begin()->first;
  int maxi = cnt.rbegin()->first;
  if (mini != maxi-1) return false;
  int left_color = maxi - cnt.begin()->second;
  if (left_color <= 0) return false;
  int left = cnt.rbegin()->second;
  return 2 * left_color <= left;
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    {
      int x; scanf("%d", &x);
      ++cnt[x];
    }
  puts(ans()?"Yes":"No");
}

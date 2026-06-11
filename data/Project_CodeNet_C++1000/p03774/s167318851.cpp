#include <iostream>      // cout, endl, cin
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, make_tuple
#include <cstdint>       // int64_t, int*_t
#include <cstdio>        // printf
#include <map>           // map
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <deque>         // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset>        // bitset
#include <cctype>        // isupper, islower, isdigit, toupper, tolower

using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
  if (a % b == 0)
  {
    return (b);
  }
  else
  {
    return (gcd(b, a % b));
  }
}

ll lcm(ll a, ll b)
{
  return a * b / gcd(a, b);
}

int main()
{
  ll n, m;
  cin >> n >> m;
  ll a[n], b[n], c[m], d[m];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> c[i] >> d[i];
  }
  ll ans[n];
  ll dist = 0;
  for (int i = 0; i < n; i++)
  {
    dist = 4*100000000 + 1;
    ll num = 0;
    for (int j = 0; j < m; j++)
    {
     ll kyori = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if (dist > kyori)
      {
        dist = kyori;
        num = j + 1;
      }
    }
    ans[i] = num;
  }
  for (int i = 0; i < n; i++)
  {
    cout << ans[i] << endl;
  }
}
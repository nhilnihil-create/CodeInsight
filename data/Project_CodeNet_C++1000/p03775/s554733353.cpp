#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

ll keta(ll tmp)
{
  ll i = 1;
  while (tmp / 10 >= 1) {
    i++;
    tmp /= 10;
  }
  return i;
}

ll f(ll a, ll b)
{
  return max(keta(a), keta(b));
}

int main()
{
  ll n;
  cin >> n;
  ll res = LLINF;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      ll a = i;
      ll b = n / i;
      ll c = f(a, b);
      res = min(res, c);
    }
  }
  cout << res << endl;
}

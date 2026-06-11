#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vll vector<ll>
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll n, m;std::cin >> n >> m;
  vvl d = vv(n+m, 2, 0, ll);
  re(i, n){
    std::cin >> d[i][0];
    d[i][1] = 1;
  }
  re(i, m)std::cin >> d[i+n][0];

  sort(d.begin(), d.end());
  ll ans = 0;

  ll a = m+1, b = n+1;

  re(i, n+m){
    ans += d[i][0] * (d[i][1]==1?a:b);
    (d[i][1]==1?b:a) = max((ll)0, d[i][1]==1?b-1:a-1);
  }
  std::cout << ans << '\n';
  return 0;
}

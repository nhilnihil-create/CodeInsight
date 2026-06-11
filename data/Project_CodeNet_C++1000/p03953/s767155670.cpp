#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d>>(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll n;std::cin >> n;
  vll a(n);re(i, n) scanf("%lld", &a[i]);
  vll b(n, 0);
  for(int i=1;i<n;i++) b[i] = a[i] - a[i-1];

  vll p(n);
  for(int i=0;i<n;i++) p[i] = i;

  vvl nxt = VV(64, n, 0, ll);
  ll m, k;std::cin >> m >> k;
  vll ans(n);
  ans[0] = a[0];
  for(int i=0;i<m;i++){
    ll x;scanf("%lld", &x);x--;
    swap(p[x], p[x+1]);
  }
  nxt[0] = p;
  for(int i=0;i<63;i++){
    for(int j=0;j<n;j++){
      nxt[i+1][j] = nxt[i][nxt[i][j]];
    }
  }
  for(int i=0;i<n;i++) p[i] = i;
  for(int i=0;i<64;i++){
    if(((k>>i)&1)==0) continue;
    for(int j=0;j<n;j++) p[j] = nxt[i][p[j]];
  }

  for(int i=1;i<n;i++) ans[i] = ans[i-1] + b[p[i]];
  for(int i=0;i<n;i++) std::cout << ans[i] << "\n";
  return 0;
}

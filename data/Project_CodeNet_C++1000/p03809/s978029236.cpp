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
#include <iomanip>
#define vll vector<ll>
#define vvv vector<vvl>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvvl(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
typedef __int128_t lll;
using namespace std;

void out(bool f){
  std::cout << (f?"YES":"NO") << '\n';
  exit(0);
}
vvl G = vv(100001, 0, 0, ll);
ll root;
vll a(100001), th(100001, -1);

ll dfs(ll now, ll from){
  if(G[now].size()==1) return th[now] = a[now];
  ll s = 0, m = 0;
  for(int i=0;i<G[now].size();i++){
    if(G[now][i]==from) continue;
    ll tmp = dfs(G[now][i], now);
    s += tmp, m = max(m, tmp);
  }
  ll T, L, K;
  if(now==root) {
    K = min(s-m, s/2);
    //std::cout << a[root] << " " << s << " " << m << '\n';
    out(s%2==0&&K==a[now]&&s/2>=m);
    return -1;
  }else{
    T = 2*a[now]-s, L = (s - T)/2, K = min(s-m, s/2);
    if(T<0||L>K||L<0) out(0);
  }
  return th[now] = T;
}

int main(int argc, char const *argv[]) {
  ll x, y, n;std::cin >> n;
  rep(i, 1, n+1) std::cin >> a[i];
  re(i, n-1){
    std::cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  if(n==2) out(a[1]==a[2]);
  for(int i=1;i<=n;i++) if(G[i].size()!=1) root = i;
  dfs(root, -1);
  out(1);
  return 0;
}

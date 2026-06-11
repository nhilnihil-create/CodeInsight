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
#define VV(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

vll color(100001, -1);
vvl G = VV(100001, 0, 0, ll);

ll root;
bool nibu;
bool zero;
ll z = 0;
void dfs(ll now, ll from, ll b){
  if(color[now]!=-1){
    if(color[now]!=b) nibu = false;
    return;
  }
  color[now] = b;
  if(root==now&&G[now].size()==0) zero = true;
  for(auto to:G[now]){
    if(to==from) continue;
    dfs(to, now, b^1);
  }
}

int main(int argc, char const *argv[]) {
  ll n, m;std::cin >> n >> m;
  for(int i=0;i<m;i++){
    ll a, b;scanf("%lld %lld", &a, &b);a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vll dat(2, 0);
  for(int i=0;i<n;i++){
    if(color[i]!=-1) continue;
    nibu = true;
    zero = false;
    root = i;
    dfs(i, -1, 0);
    if(zero) z++;
    else dat[nibu]++;
  }
  //std::cout << dat[0] << " " << dat[1] << " " << z << '\n';
  ll ans = 0;
  for(ll i=0;i<z;i++) ans += 2*(n-i)-1;
  ans += dat[0]+2*dat[1];
  ans += 2*dat[1]*dat[0];
  ans += 1*dat[0]*(dat[0]-1);
  ans += 2*dat[1]*(dat[1]-1);

  std::cout << ans << '\n';
  return 0;
}

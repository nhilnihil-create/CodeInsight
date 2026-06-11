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
typedef long long int ll;
typedef long double ld;
using namespace std;

struct UF{
  std::vector<int> par, dep, sz;
  UF(int n){
    par.resize(n+1), dep.resize(n+1), sz.resize(n+1);
    init(n);
  }
  void init(int nu) {
    for(int iu=0;iu<=nu;iu++){
      par[iu] = iu;
      dep[iu] = 0;
      sz[iu] = 1;
    }
  }
  int find(int xu){
    if(par[xu] == xu) return xu;
    return par[xu] = find(par[xu]);
  }
  void unite(int xu, int yu){
    xu=find(xu);
    yu=find(yu);
    if(xu == yu) return;
    if(dep[xu] < dep[yu]){
      sz[yu] += sz[xu];
      par[xu] = yu;
    }else{
      par[yu] = xu;
      sz[xu] += sz[yu];
      if(dep[xu] == dep[yu]) dep[xu]++;
    }
  }
  bool same(int xu, int yu){
    return find(xu) == find(yu);
  }
};
int main(int argc, char const *argv[]) {
  ll x, y, n, k, l;std::cin >> n >> k >> l;
  UF road(n), train(n);
  for(int i=0;i<k;i++){
    std::cin >> x >> y;
    road.unite(x, y);
  }
  for(int i=0;i<l;i++){
    std::cin >> x >> y;
    train.unite(x, y);
  }
  vvl s = vv(0, 2, 0, ll);
  for(int i=1;i<=n;i++) s.push_back(vll{road.find(i), train.find(i)});
  sort(s.begin(), s.end());
  for(int i=1;i<=n;i++){
    ll t = lower_bound(s.begin(), s.end(), vll{road.find(i), train.find(i)+1}) - s.begin();
    ll k = lower_bound(s.begin(), s.end(), vll{road.find(i), train.find(i)}) - s.begin();
    std::cout << t - k << (i==n?"\n":" ");
  }

  return 0;
}

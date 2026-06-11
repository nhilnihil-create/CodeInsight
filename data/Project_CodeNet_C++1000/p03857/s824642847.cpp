#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#include <memory.h>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 2e5+1;

class UnionFindTree{
  ll par[MAXN];
  ll rank[MAXN];

public:
  void init(int n){
    for(ll i=0;i<n;i++){
      par[i] = i;
      rank[i] = 0;
    }
  }

  ll find(ll x){
    if(par[x] == x){
      return x;
    }else{
      return par[x] = find(par[x]);
    }
  }

  void unite(ll x, ll y){
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rank[x] < rank[y]){
      par[x] = y;
    }else{
      par[y] = x;
      if(rank[x] == rank[y]) rank[x]++;
    }
  }

  bool same(ll x, ll y){
    return find(x) == find(y);
  }

};

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N, K, L; cin >> N >> K >> L;
  UnionFindTree a, b;
  // 0-indexed
  a.init(N);
  b.init(N);
  for(int i=0;i<K;i++){
    int p, q; cin >> p >> q;
    a.unite(p-1, q-1);
  }
  for(int i=0;i<L;i++){
    int r, s; cin >> r >> s;
    b.unite(r-1, s-1);
  }
  map<pair<int, int>, int> mp;
  for(int i=0;i<N;i++){
    mp[make_pair(a.find(i), b.find(i))]++;
  }
  for(int i=0;i<N-1;i++){
    cout << mp[make_pair(a.find(i), b.find(i))] << " ";
  }
  cout << mp[make_pair(a.find(N-1), b.find(N-1))] << endl;
}
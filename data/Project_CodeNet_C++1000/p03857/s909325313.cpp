#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
  vector<int> par;

  UnionFind(int N) : par(N){
    for(int i=0;i<N;i++) par[i] = i;
  }

  int root(int x){
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  void unite(int x,int y){
    int rx = root(x);
    int ry = root(y);
    if(rx == ry) return;
    par[rx] = ry;
  }

  bool same(int x, int y){
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main(){
  int N,K,L;
  cin >> N >> K >> L;

  vector<int> count(N);
  for(int i=0;i<N;i++) count[i] = 1;
  UnionFind road(N);
  UnionFind train(N);

  for(int i=0;i<K;i++){
    int p,q;
    cin >> p >> q;
    road.unite(p-1,q-1);
  }
  for(int i=0;i<L;i++){
    int r,s;
    cin >> r >> s;
    train.unite(r-1,s-1);
  }

  map<pair<int, int>, int> cnt;
  for(int i=0;i<N;i++){
    cnt[make_pair(road.root(i),train.root(i))] += 1;
  }
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",cnt[make_pair(road.root(i),train.root(i))]);
  }
  printf("\n");
  return 0;
}

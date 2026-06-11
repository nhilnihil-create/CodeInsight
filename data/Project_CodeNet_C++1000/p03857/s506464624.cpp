#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<utility>
using namespace std;
struct unionfind{
  int par[200010]; // 親ノード  必要に応じて要素数を変えよう
  int rank[200010]; // ランク　必要に応じて要素数を変えよう
  unionfind(int n){
    init(n);
  }
  void init(int n){
    for(int i=0;i<=n;i++){
      par[i]=i;
      rank[i]=1;
    }
  }
  int root(int x) {
    if (par[x] == x) {
      return x;
    }
    else {
      return par[x] = root(par[x]);
    }
  }
  int size(int x){
    return rank[root(x)];
  }
  bool same(int x,int y) {
    return root(x) == root(y);
  }
  void unite(int x,int y) {
    x=root(x);
    y=root(y);
    if(x==y){
      return;
    }
    if(rank[x]<rank[y]){
      swap(x,y);
    }
    rank[x]=rank[x]+rank[y];
    par[y]=x;
  }
};
int main(){
  int i,n,k,l,p,q;
  pair<int,int> b;
  map<pair<int,int>,int> store;
  scanf("%d %d %d\n",&n,&k,&l);
  unionfind tree(n);
  unionfind tree1(n);
  for(i=0;i<k;i++){
    scanf("%d %d\n",&p,&q);
    tree.unite(p,q);
  }
  for(i=0;i<l;i++){
    scanf("%d %d\n",&p,&q);
    tree1.unite(p,q);
  }
  for(i=1;i<=n;i++){
    b.first=tree.root(i),b.second=tree1.root(i);
    store[b]++;
  }
  for(i=1;i<=n;i++){
    b.first=tree.root(i),b.second=tree1.root(i);
    if(i==1){
      printf("%d",store[b]);
    }
    else{
      printf(" %d",store[b]);
    }
  }
  printf("\n");
  return 0;
}
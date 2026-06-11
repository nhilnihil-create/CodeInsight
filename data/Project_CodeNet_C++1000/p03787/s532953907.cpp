#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<iomanip>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
struct UnionFind{
  vector<int> par;
  vector<int> sizes;
  UnionFind(int n) : par(n), sizes(n, 1) {
    rep(i,n) par[i] = i;
  }
  int root(int x) {
    if (x == par[x]) return x;
    return par[x] = root(par[x]);
  }
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (sizes[x] < sizes[y]) swap(x, y);
    par[y] = x;
    sizes[x] += sizes[y];
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  int size(int x) {
    return sizes[root(x)];
  }
};
int main(){
	int N,M;
	scan(N);scan(M);
	int A[200001],B[200001];
	UnionFind uf(N*2);
	rep(i,M){
		scan(A[i]);scan(B[i]);
		A[i]--; B[i]--;
		uf.unite(A[i],B[i]+N);
		uf.unite(A[i]+N,B[i]);
	}
	ll alonenum=0,nibu=0,hinibu=0;
	rep(i,N){
		if(uf.root(i)==i||uf.root(i)==i+N){
			if(uf.size(i)==1) alonenum++;
			else if(uf.same(i,i+N)) hinibu++;
			else nibu++;
		}
	}
	ll ans=N*alonenum*2-alonenum*alonenum+nibu*nibu*2+hinibu*nibu*2+hinibu*hinibu;
	prin(ans);
	return 0;
}

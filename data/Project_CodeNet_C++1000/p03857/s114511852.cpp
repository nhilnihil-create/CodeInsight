#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

#define REP(i,n) for(int i=0;i<n;++i)
#define REPR(i,n) for(int i=n;i>=0;--i)
#define REPI(itr,v) for(auto itr=v.begin();itr!=v.end();++itr)
#define REPIR(itr,v) for(auto itr=v.rbegin();itr!=v.rend();++itr)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define SORT(v,n) sort(v, v+n)
#define SORTV(v) sort(v.begin(), v.end())
#define ALL(v) v.begin(),v.end()
#define llong long long
#define INF 999999999
#define SUR 1000000007
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define MP make_pair
#define MAX 200000
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

using namespace std;

typedef pair<int,int> pii;

int par1[MAX], rank1[MAX], par2[MAX], rank2[MAX];
int n;

void init(int par[]){
  for(int i = 0; i < n; i++)
    par[i] = i;
}

int find(int x, int par[]){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x], par);
  }
}

void unite(int x, int y, int par[], int rank[]){
  x = find(x, par);
  y = find(y, par);

  if(x == y)
    return;

  if(rank[x] > rank[y]){
    par[y] = x;
  }else{
    par[x] = y;
    if(rank[x] == rank[y])
      rank[y]++;
  }

}

int same(int x, int y,int par[]){
  return find(x, par) == find(y, par);
}

int main(){

  int k, l;
  scanf("%d %d %d", &n , &k, &l);

  init(par1); init(par2);
  REP(i,k){
    int p, q;
    scanf("%d %d", &p, &q);
    p--; q--;
    unite(p, q, par1, rank1);
  }

  REP(i,l){
    int r, s;
    scanf("%d %d", &r, &s);
    r--; s--;
    unite(r, s, par2, rank2);
  }

  map<pii, int> mp;
  REP(i,n){
    mp[pii(find(i, par1), find(i, par2))]++;
  }

  REP(i,n){
    printf("%d ", mp[pii(find(i, par1), find(i, par2))]);
  }
  printf("\n");
  return 0;
}


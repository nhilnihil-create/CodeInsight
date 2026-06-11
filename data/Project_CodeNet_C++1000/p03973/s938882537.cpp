#include<cstdio>
#include<queue>
#include<utility>
#include<cstring>
#include<stack>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<map>
#define MAX_N 100001
#define INF_INT 2147483647
#define INF_LL 9223372036854775807
#define REP(i,n) for(int i=0;i<(int)(n);i++)
void init(int n);
int find(int n);
void unite(int x,int y);
bool same(int x, int y);
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
bool cmp_P(const P &a,const P &b){
  return a.second < b.second;
}
int main()
{
  ll tmp,res=0,N,A[100001],mi=0;
  cin >> N;
  REP(i,N)cin >> A[i];
  REP(i,N){
    if(A[i] == mi+1)
      mi++;
    else if(A[i] == mi)
      continue;
    else{
      res += A[i] % (mi+1) == 0 ? A[i]/(mi+1) - 1 : A[i]/(mi+1);
    }
    if(i == 0)
      mi = 1;
  }
  cout << res << endl;
  return 0;
}

int par[MAX_N];
int ranks[MAX_N];

//n要素で初期化
void init(int n){
  REP(i,n){
    par[i] = i;
    ranks[i] = 0;
  }

}

//木の根を求める
int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x,int y){
  x = find(x);
  y = find(y);
  if(x == y) return ;
  if(ranks[x] < ranks[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(ranks[x] == ranks[y]) ranks[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}


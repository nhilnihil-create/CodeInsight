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
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
void init(int n);
int find(int n);
void unite(int x,int y);
bool same(int x, int y);
ll bpow(ll,ll,ll);
typedef vector<int> vec;
typedef vector<vec> mat;
mat mul(mat &A,mat &B);
mat pow(mat A,ll n);
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
bool dp[5001];
vector<ll> a(0);
ll N,K,res=0;
bool solve(int mid){

  fill(dp,dp+5001,false);
  dp[0] = true;
  for(int j=0;j<a.size();j++){
    if(j == mid)
      continue;
    for(int d=5000;d>=0;d--){
      if(d-a[j] >= 0)
        if(dp[d-a[j]])
          dp[d] = true;
    }
  }
  for(int k=K-1;k>=K-a[mid];k--){
    if(dp[k]){
      return true;
      break;
    }
  }
  return false;
}
int main()
{
  
  cin >> N >> K;
  a =  vector<ll>(N,0);
  REP(i,N){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  int ok = a.size()-1;
  int ng = 0;
  while(abs(ok-ng) > 1){
    int mid=(ok+ng)/2;
    if(solve(mid)){
      ok = mid;
    }else
      ng = mid;
  }
  if(solve(ng)){
    cout << ng << endl;
  }else if(solve(ok))
    cout << ok << endl;
  else
    cout << N << endl;
  
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

ll bpow(ll a, ll n,ll mod){
  int i = 0;
  ll res=1;
  while(n){
    if(n & 1)
      res = (res*a) % mod;
    a = (a*a) % mod;
    n >>= 1;
  }
  return res;
}
const int MOD = 1000000007;
mat mul(mat &A, mat &B){
  mat C(A.size(),vec(B[0].size()));
    REP(i,A.size())REP(k,B.size())REP(j,B[0].size()){
    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
  }
  return C;
}

mat pow(mat A,ll n)
{
  mat B(A.size(),vec(A.size()));
  REP(i,A.size()){
    B[i][i] = 1;
  }
  while(n > 0){
    if ( n & 1) B = mul(B,A);
    A = mul(A,A);
    n >>= 1;
  }
  return B;
}

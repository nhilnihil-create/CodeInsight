#include<bits/stdc++.h>
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
int dx[9] = {-1,0,1,-1,0,1,-1,0,1};
int dy[9] = {-1,-1,-1,0,0,0,1,1,1};


bool cmp_P(const P &a,const P &b){
  return a.second < b.second;
}
int main()
{
  ll N,H,W,a,b,res[10]={0},t=0;
  map<P,bool> mp,visited;
  vector<P> v(0);
  cin >> H >> W >> N;
  REP(i,N){
    cin >> a >> b;
    mp[P(a,b)] = true;
    v.push_back(P(a,b));
  }
  REP(i,N){
    REP(d,9){
      int cnt = 0;
      int x=v[i].second+dx[d],y=v[i].first+dy[d];
      if(visited[P(y,x)] || y >= H || x >= W || x <= 1 || y <= 1)
        continue;
      visited[P(y,x)] = true;
      REP(j,9){
        cnt += mp[P(y+dy[j],x+dx[j])];
      }
      res[cnt]++;
    }
  }
  REP(i,10)t += res[i];
  t = (H-2)*(W-2)-t;
  res[0] = t;
  REP(i,10)cout << res[i] << endl;
  
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

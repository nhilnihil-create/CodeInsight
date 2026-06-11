#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1ll << 62)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};



int main(){
  
  ll  n,m,R;
  cin >> n >> m >> R;
  vector<ll> r(R);
  REP(i,R)cin >> r[i],r[i]--;
  sort(ALL(r));
  vector<vector<ll>> dist(n,vector<ll>(n,(1 << 30)));
  REP(i,n)dist[i][i] = 0;
  REP(i,m){
    ll a,b,c;cin >> a >> b >> c;
    a--,b--;
    dist[a][b] = dist[b][a] = c;
  }
  REP(k,n)REP(i,n)REP(j,n)dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
  ll res = INF;
  do{
    ll sum = 0;
    REP(i,R-1)sum += dist[r[i]][r[i+1]];
    res = min(res,sum);
  }while(next_permutation(ALL(r)));
  cout << res << endl;


  

  return 0;
}
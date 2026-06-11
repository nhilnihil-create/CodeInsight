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
#define INF (1 << 30)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};


int main(){

  int n,w;
  cin >> n >> w;
  vector<vector<ll>> v(4);
  ll w1,v1;
  cin >> w1 >> v1;
  v[0].push_back(v1);
  REP(i,n-1){
    int x,y;cin >> x >> y;
    v[x-w1].push_back(y);
  }
  REP(i,4)sort(ALL(v[i]),greater<ll>());
  vector<vector<ll>> s(4,vector<ll>(n+1,0));
  REP(i,4)REP(j,v[i].size())s[i][j+1] = s[i][j]+v[i][j];
  ll res = 0;
  REP(i,v[0].size()+1){
    REP(j,v[1].size()+1){
      REP(k,v[2].size()+1){
        REP(l,v[3].size()+1){
          if(w1*(i+j+k+l)+j+k*2+l*3 > w)continue;
          ll sum = s[0][i] + s[1][j] + s[2][k] + s[3][l];
          res = max(res,sum);
        }
      }
    }
  }
  cout << res << endl;



  

  return 0;
}

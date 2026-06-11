#include<bits/stdc++.h>

using namespace std;
using ll = long long;
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

  int H,W,n;
  cin >> H >> W >> n;
  queue<int> que;
  REP(i,n){
    int x;cin >> x;
    REP(j,x)que.push(i+1);
  }
  vector<vector<int>> res(H,vector<int>(W));
  bool is = true;
  REP(i,H){
    if(is){
      REP(j,W)res[i][j] = que.front(),que.pop();
      is = false;
    }else{
      REPD(j,W)res[i][j] = que.front(),que.pop();
      is = true;
    }
  }
  REP(i,H)REP(j,W)j == W-1 ? cout << res[i][j] << endl : cout << res[i][j] << " ";
  





  

  return 0;
}

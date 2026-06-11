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


ll dist[100000];

struct edge{
  ll to,we;
  bool operator<(const edge &other)const{
    return we < other.we;
  }
};

int main(){
  
  FILLl(dist,100000,-1);
  int n;
  cin >> n;
  vector<vector<edge>> v(n);
  REP(i,n-1){
    ll a,b,c;cin >> a >> b >> c;
    a--,b--;
    v[a].push_back({b,c});
    v[b].push_back({a,c});
  }
  int Q,K;
  cin >> Q >> K;
  K--;
  queue<int> que;
  que.push(K);
  dist[K] = 0;
  while(!que.empty()){
    int ov = que.front();que.pop();
    for(auto nv : v[ov]){
      if(dist[nv.to] != -1)continue;
      dist[nv.to] = dist[ov] + nv.we;
      que.push(nv.to);
    }
  }
  REP(i,Q){
    int x,y;cin >> x >> y;
    x--,y--;
    cout << dist[x] + dist[y] << endl;
  }




  return 0;
}
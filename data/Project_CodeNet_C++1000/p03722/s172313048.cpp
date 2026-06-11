#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

vector<pair<ll,ll>> v[1010];
ll dist[1010];
vector<int> used(1010,0);

void bfs(){
  queue<int> q;
  q.push(0);
  dist[0]=0;
  while(q.size()){
    int x=q.front(); q.pop();
    if(used[x]>3000){ continue; }
    for(auto e:v[x]){
      if(dist[e.F] > dist[x] + e.S){
        dist[e.F] = dist[x] + e.S;
        used[e.F]++;
        q.push(e.F);
      }
    }
  }
}

int main(){
  int n,m;
  cin >> n >> m;
  rep(i,m){
    ll a,b,c;
    cin >> a >> b >> c; a--; b--;
    v[a].push_back({b,-c});
  }
  rep(i,n){ dist[i]=longinf; }
  
  bfs();
  
  if(used[n-1]>1000){ 
    cout << "inf" << endl; 
  } else {
    cout << -dist[n-1] << endl; 
  }
  return 0;
}

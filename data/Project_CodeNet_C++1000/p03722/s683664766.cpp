#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(ll i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln = '\n';

const int mx=200010;
const ll mod=1e9+7;

vector<pair<ll,ll>> v[2510];
vector<ll> dist(2510,longinf);
vector<int> used(2510,0);
 
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
  
  bfs();
  
  if(used[n-1]>1010){ 
    cout << "inf" << endl; 
  } else {
    ll ans = -dist[n-1];
    cout << ans << endl; 
  }
  return 0;
}
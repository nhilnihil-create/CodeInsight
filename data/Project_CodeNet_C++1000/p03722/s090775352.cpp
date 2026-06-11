#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<deque>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#include<regex>
#include<bitset>
#include<complex>
#include<chrono>
#include<random>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

ll gcd(ll n, ll m) {
	ll tmp;
	while (m!=0) {
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m) {
	return abs(n * m) / gcd(n, m);//gl=xy
}
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
using namespace std;

//ここから

//頂点fromから頂点toへのcost
struct edge{
  ll from,to,cost;
  edge (ll from,ll to,ll cost):from(from),to(to),cost(cost){}
};

vector<ll>d;//最短距離

void bellman_ford(vector<edge> &es,int V,int s){//es:頂点,costという要素からなる、辺についての配列、V:頂点数,s:スタート地点
    d.resize(V+1,INF);
    ll cnt=0;
    d[s]=0;
    bool upgrade=true;
    while(upgrade){
      ++cnt;
      if(cnt>V){
        for(int i=0;i<V;i++){
		      for(auto &e:es){
			      if(d[e.to]!=INF && d[e.to] > d[e.from] + e.cost)d[e.to] = -INF;
		      }
	      }
        return;
      }
      upgrade=false;//フラグ
    //それぞれの頂点につき1回ずつしか通らないため、V-1回しかループは実行されない(V回目があるときは負の辺を含む)
        for(auto &e:es){//esの変更が反映される
            if(d[e.from]==INF)continue;
            if(d[e.to]>d[e.from]+e.cost){
            d[e.to]=d[e.from]+e.cost;
            upgrade=true;
            }
        }
    }
}

using P=pair<ll,ll>;
void solve(){
  int n,m;
  cin>>n>>m;
  vector<edge>es;
  rep(i,m){
    ll a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    es.eb(a,b,-c);
  }
  bellman_ford(es,n,0);
  if(d[n-1]==-INF)cout<<"inf";
  else cout<<-d[n-1]<<endl;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}

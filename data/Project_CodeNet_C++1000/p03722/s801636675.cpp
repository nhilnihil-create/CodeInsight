#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
#define FORR(I,A,B) for(ll I = ll((B)-1); I >= ll(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd_(ll a,ll b){if(a%b==0)return b;return gcd_(b,a%b);}
ll lcm_(ll a,ll b){ll c=gcd_(a,b);return ((a/c)*(b/c)*c);}
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=ll(1e16)+ll(7);
const ll MOD=1000000007LL;
#define out(a) cout<<fixed<<setprecision((a))
//tie(a,b,c) = make_tuple(10,9,87);
#define pop_(a) __builtin_popcount((a))
ll keta(ll a){ll r=0;while(a){a/=10;r++;}return r;}



// http://sesenosannko.hatenablog.com/entry/2017/09/01/214852
// https://beta.atcoder.jp/contests/abc061/submissions/3322496
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3166760#1
// 0-index
struct Bellman_Ford{
  struct edge{ll from, to, cost;};
  ll inf = 1e16;
  vector<edge> es;
  vector<ll> d;
  ll V,E;
  void init(ll v,ll e){
    V = v; E = e;
    d.resize(V);
  }
  void shortest_path(ll s){
    FOR(i,0,V) d[i] = inf;
    d[s] = 0;
    FOR(i,0,V){
      FOR(j,0,E){
        edge e = es[j];
        if(d[e.from]!=inf && d[e.to]>d[e.from] + e.cost){
          d[e.to] = d[e.from] + e.cost;
        }
      }
    }
  }
  bool find_negative_loop(){// all graph
    FOR(i,0,V)d[i] = 0;
    FOR(i,0,V){
      FOR(j,0,E){
        edge e = es[j];
        if(d[e.to]>d[e.from] + e.cost){
          d[e.to] = d[e.from] + e.cost;
          if(i == V-1) return true;
        }
      }
    }
    return false;
  }
  bool find_negative_loop(ll s){// from s
    ll cnt = 0;
    FOR(i,0,V)d[i]=inf;
    d[s]=0;
    while(true){
      bool update = false;
      cnt++;
      FOR(i,0,E){
        edge e = es[i];
        if(d[e.from] != inf && d[e.to]>d[e.from] + e.cost){
          d[e.to] = d[e.from] + e.cost;
          if(cnt == V){
            return true;
          }
          update = true;
        }
      }
      if(! update)break;
    }
    return false;
  }
  bool shortest_path(int s, int t){ // t: destination
    FOR(i,0,V)d[i] = inf;
    d[s] = 0;
    FOR(i,0,2*V){
      FOR(j,0,E){
        edge e = es[j];
        if(d[e.from]!=inf && d[e.to]>d[e.from] + e.cost){
          d[e.to] = d[e.from] + e.cost;
          if(i>=V-1 && e.to==t) return true;
        }
      }
    } 
    return false;
  }
};


int main(){

  ll N,M;
  cin >> N >> M;
  Bellman_Ford bf;
  bf.init(N+1,M);
  FOR(i,0,M){
    ll a,b,c;
    cin >> a >> b >> c;
    bf.es.push_back({a,b,-c});
  }
  if(bf.shortest_path(1,N)){
    cout << "inf" << endl;
  }else{
    cout << -bf.d[N] << endl;
  }

}



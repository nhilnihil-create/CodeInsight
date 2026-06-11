#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define AND(x,y,z) 
#define DUMP(xs) for (auto x:xs) cout<<x<<' ';cout<<endl
#define DUMPP(xs) for (auto x:xs) cout<<'('<<x.first<<','<<x.second<<')';cout<<endl
#define FOR(i,a,b) for (ll i=(ll)(a);i<(ll)(b);++i)
#define OUT(x) cout<<x<<endl
#define REP(i,n) FOR(i,0,n)
#define YES(cond) cond ? OUT("YES") : OUT("NO")
#define Yes(cond) cond ? OUT("Yes") : OUT("No")

template<class T> T gcd(const T x,const T y){if(!y){return x;}return gcd(y,x%y);}
template<class T> T lcm(const T x,const T y){return x/gcd(x,y)*y;};
template<class T> T modpow(const T x,const T n,const T mod) {
  T res=1;while(n>0){if(n%2)res=res*x%mod;x=x*x%mod;n/=2;};return res;
}
template<class T> bool alltrue(const T &a){return all_of(ALL(a),[](bool x){return x;});}
template<class T> bool anytrue(const T &a){return any_of(ALL(a),[](bool x){return x;});}
template<class T> bool contain(const T &a,const T &b){for(auto x:b){if (a.find(x)==a.end()){return false;}}return true;}
template<class T> bool mmax(T &m,const T q){ if (m < q) {m = q; return true;} else return false; }
template<class T> bool mmin(T &m,const T q){ if (m > q) {m = q; return true;} else return false; }
template<class T> int siz(const T &a) {return (int)a.size();}
template<class T> set<T> devisers(T n) {
  set<T> res;for(T i=1;i<(T)sqrt(n)+1;i++){if(n%i==0){res.insert(i);res.insert(n/i);}}return res;
}
template<class T> void concat(T &a, const T &b){a.insert(a.end(),b.begin(),b.end());}
template<class T> void getand(const T &a,const T &b,T &c) {
  set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.end()));
}
template<class T> void getor(const T &a,const T &b,T &c) {
  set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.end()));
}

typedef long long ll;
typedef pair<ll, ll> P;

const int MOD=1e9+7;
const int MAX=1e5+100;

vector<ll> bellman_ford(int V, int s, vector<vector<P>> &G) {
  vector<ll> d(V,-LLONG_MAX);d[s]=0;
  REP(i,V-1) {
    REP(v,V) {
      if (d[v]==-LLONG_MAX) continue;
      for (P p:G[v]) {
        mmax(d[p.first],d[v]+p.second);
      }
    }
  }
  return d;
}

vector<bool> loop_checker(int V, vector<ll> &d, vector<vector<P>> &G) {
  vector<bool> res(V,false);
  REP(v,V) {
    if (d[v]==-LLONG_MAX) continue;
    for (P p:G[v]) {
      if (d[p.first]<d[v]+p.second) {
        d[p.first] = d[v]+p.second;
        res[v] = true;
        res[p.first] = true;
      }
    }
  }
  return res;
}

int main() {
  // 到着するまでのスコアの最大値。無限はinf
  // 脱出可能な閉路で、一周した結果がプラスならinf
  int N,M;cin>>N>>M;
  // グラフ作る
  vector<vector<P>> G(N);
  REP(i,M) {
    ll a,b,c;cin>>a>>b>>c;
    a--;b--;
    G[a].push_back({b,c});
  }
  vector<ll> d = bellman_ford(N,0,G);
  vector<bool> lc = loop_checker(N,d,G);
  (lc[N-1]) ? OUT("inf") : OUT(d[N-1]);

  return 0;
}
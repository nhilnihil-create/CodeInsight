#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/

struct Edge {
  ll s, t, w;
  Edge(ll s, ll t, ll w): s(s), t(t), w(w){}
};

ll N, M;
vector<Edge> es;
ll d[1111];

ll bellmanFord(ll r) {
  ll i;
  for(i=0; i<N; i++) d[i]=INF;
  d[r]=0;
    
  for(ll cnt=0; cnt<=N; cnt++) {
    for(i=0; i<es.size(); i++) {
      Edge e=es[i];
      if(d[e.s]!=INF && d[e.t]>d[e.s]+e.w) {
        d[e.t]=d[e.s]+e.w;
      }
    }
  }
  
  ll p=d[N-1];
  for(i=0; i<es.size(); i++) {
    Edge e=es[i];
    if(d[e.s]!=INF && d[e.t]>d[e.s]+e.w) {
      d[e.t]=d[e.s]+e.w;
    }
  }
  
  if(d[N-1]!=p) return 1;
  else return 0;
}


int main(void) {
  ll i, j, k;
  cin >> N >> M;
  
  for(i=0; i<M; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    es.push_back(Edge(a, b, -c));
  }
  
  if(bellmanFord(0))
    pt("inf");
  else
    pt(-d[N-1]);
  
  
}


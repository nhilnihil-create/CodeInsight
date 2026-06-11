#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define ALLTRUE(xs) all_of(ALL(xs),[](bool x){return x;})
#define AND(x,y,z) set_intersection((x).begin(),(x).end(),(y).begin(),(y).end(),inserter((z),(z).end()))
#define ANYTRUE(xs) any_of(ALL(xs),[](bool x){return x;})
#define CONCAT(x,y) (x).insert((x).end(),(y).begin(),(y).end())
#define DUMP(xs) for (auto x:xs) cout<<x<<' ';cout<<endl
#define FOR(i,a,b) for (int i=(int)(a);i<(int)(b);++i)
#define OR(x,y,z) set_union((x).begin(),(x).end(),(y).begin(),(y).end(),inserter((z),(z).end()))
#define OUT(x) cout<<x<<endl
#define REP(i,n) FOR(i,0,n)

struct edge { int to,cost; };
struct ftedge { int from,to,cost; };

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<int> VECINT;
typedef vector<ll> VECLL;

vector<ll> bellman_ford(int V, int s, vector<ftedge> es) {
  vector<ll> d(V,LLONG_MIN);d[s]=0;
  REP(i,V-1) {
    for (ftedge e:es) {
      if (d[e.from]!=LLONG_MIN && d[e.to]<d[e.from]+e.cost) {
        d[e.to] = d[e.from]+e.cost;
      }
    }
  }
  return d;
}

bool loop_checker(int V, vector<ll> &d, vector<ftedge> es) {
  vector<bool> checker(V,false);
  for (ftedge e:es) {
    if (d[e.from]!=LLONG_MIN && d[e.to]<d[e.from]+e.cost) {
      d[e.to] = d[e.from]+e.cost;
      checker[e.from] = true;
      checker[e.to] = true;
    }
  }

  return checker[V-1];
}

int main() {
  int N,M;cin>>N>>M;
  vector<ftedge> es;
  REP(i,M) {
    int a,b,c;cin>>a>>b>>c;
    a--;b--;
    es.push_back({a,b,c});
  }
  vector<ll> d = bellman_ford(N,0,es);
  loop_checker(N,d,es) ? OUT("inf") : OUT(d[N-1]);

  return 0;
}
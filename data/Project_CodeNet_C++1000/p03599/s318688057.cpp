#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define show(x) cout << #x << " = " << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;

int main() { 
  int a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  vi water,suger;
  rep(i,f+1){
    rep(j,f+1){
      int x = i*c+j*d;
      int y = i*a*100+j*b*100;
      if(x<=f)suger.push_back(x);
      if(y<=f)water.push_back(y);
    }
  }
  int ax=0,ay=0;
  double rate = 0;
  for(auto s:suger){
    for(auto w:water){
      if(s+w>f)continue;
      double z = (double)s/((double)s+(double)w);
      if(z < rate)continue;
      if((double)s/(double)e*100 > w)continue;
      ax = s;
      ay = w;
      rate = z;
    }
  }
  cout<<ax+ay<<" "<<ax<<endl;
  return 0;
}
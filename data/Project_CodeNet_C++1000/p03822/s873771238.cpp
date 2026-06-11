#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef pair<double,double> PD;
typedef pair<int,P> ed;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;

int dfs(int k,vvi &G) {
  if(sz(G[k])==0) return 0;
  vi res;
  for(auto t:G[k]) {
    res.push_back(dfs(t,G));
  }
  sort(rng(res));
  reverse(rng(res));
  int r = 0;
  rep(i,sz(res)) {
    chmax(r,res[i]+i+1);
  }
  return r;
}
  
int main() {
  int N;
  cin >> N;
  vvi G(N);
  srep(i,1,N) {
    int j;
    cin >> j;
    j--;
    G[j].push_back(i);
  }
  cout << dfs(0,G) << endl;
  return 0;
}
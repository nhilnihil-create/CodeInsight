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
  
int main() {
  int N,M;
  cin >> N >> M;
  vi a(M),b(M),c(M);
  rep(i,M) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
  }
  vvi G(N,vi(N,INF));
  rep(i,N) {
    G[i][i] = 0;
  }
  rep(i,M) {
    G[a[i]][b[i]]=c[i];
    G[b[i]][a[i]]=c[i];
  }
  rep(k,N) {
    rep(i,N) {
      rep(j,N) {
        if(G[i][j]>G[i][k]+G[k][j]) {
          G[i][j]=G[i][k]+G[k][j];
        }
      }
    }
  }
  int ans = 0;
  rep(i,M) {
    if(G[a[i]][b[i]]<c[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}
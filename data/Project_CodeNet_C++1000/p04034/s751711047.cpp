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
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;
  


int main() {
  int N,M;
  cin >> N >> M;
  vi xs(M),ys(M);
  rep(i,M) {
    cin >> xs[i] >> ys[i];
    xs[i]--;
    ys[i]--;
  }
  vi used(N,0);
  vi num(N,1);
  used[0]++;
  rep(i,M) {
    int f=xs[i];
    int t=ys[i];
    if(!used[f]) {
      num[f]--;
      num[t]++;
      continue;
    }
    num[f]--;
    num[t]++;
    used[t]++;
    if(num[f]==0) {
      used[f]=0;
    }
  }
  int ans = 0;
  rep(i,N) {
    if(used[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}
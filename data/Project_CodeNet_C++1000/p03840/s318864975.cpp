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
  ll i,o,t,j,l,s,z;
  cin >> i >> o >> t >> j >> l >> s >> z;
  ll ans = 0;
  ans += o;
  ll e = 0;
  {
    ll ni = i,nj = j,nl = l;
    ll c = 0;
    if (ni > 0 && nj > 0 && nl > 0) {
      ni--;nj--;nl--;
      c += 3;
    }
    c += (ni/2)*2;
    c += (nj/2)*2;
    c += (nl/2)*2;
    chmax(e,c);
  }
  {
    ll ni = i,nj = j,nl = l;
    ll c = 0;
    c += (ni/2)*2;
    c += (nj/2)*2;
    c += (nl/2)*2;
    chmax(e,c);
  }
  ans += e;
  cout << ans << endl;
  return 0;
}
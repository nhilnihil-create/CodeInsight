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
  ll a,b,c;
  cin >> a >> b >> c;
  set<pair<ll,ll>> memo;
  memo.insert(pair<ll,ll>(a,b));
  int ans = 0;
  for(;a%2==0&&b%2==0&&c%2==0;ans++) {
    ll a2=a/2;
    ll b2=b/2;
    ll c2=c/2;
    a=b2+c2;
    b=a2+c2;
    c=a2+b2;
    if(memo.count(pair<ll,ll>(a,b))) {
      cout << -1 << endl;
      return 0;
    }
    memo.insert(pair<ll,ll>(a,b));
  }
  cout << ans << endl;
  return 0;
}
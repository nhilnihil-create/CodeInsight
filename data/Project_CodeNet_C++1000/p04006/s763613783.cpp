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

int N;

void build(vi &segtree,int idx,int val) {
  int s = sz(segtree) - (N-idx);
  segtree[s] = val;
  while(1) {
    if(s == 0) break;
    s = (s-1)/2;
    segtree[s] = min(segtree[s*2+1],segtree[s*2+2]);
  }
}

int _query(vi &segtree,int a,int b,int idx,int l,int r) {
  if(a <= l && r <= b) return segtree[idx];
  if(r <= a || b <= l) return INF;
  int vl = _query(segtree,a,b,idx*2+1,l,(l+r)/2);
  int rl = _query(segtree,a,b,idx*2+2,(l+r)/2,r);
  return min(vl,rl);
}

int query(vi &segtree,int l,int r) {
  return _query(segtree,l,r+1,0,0,N);
}
  
int main() {
  int n,x;
  cin >> n >> x;
  vi a(n);
  rep(i,n) {
    cin >> a[i];
  }
  N = 1;
  int len = 1;
  while(N < n) {
    N *= 2;
    len += N;
  }
  vi segtree(len,INF);
  rep(i,n) {
    build(segtree,i,a[i]);
  }
  ll ans = LINF;
  rep(k,n) {
    ll sum = 0;
    rep(i,n) {
      if(k+i>=n) {
        int l = i;
        int r = n-1;
        int res = query(segtree,l,r);
        l = 0;
        r = (k+i)%n;
        res = min(res,query(segtree,l,r));
        sum += res;
      } else {
        sum += query(segtree,i,k+i);
      }
    }
    sum += 1ll * x * k;
    ans = min(ans,sum);
  }
  cout << ans << endl;
  return 0;
}
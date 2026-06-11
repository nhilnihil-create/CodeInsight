#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;
#define dame { puts("-1"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
  
int main() {
  int N;
  cin >> N;
  vi t(N),a(N);
  rep(i,N) {
    cin >> t[i];
  }
  rep(i,N) {
    cin >> a[i];
  }
  vi ans(N,-1);
  rep(i,N) {
    if(i == 0){
      ans[i] = t[i];
    } else if(t[i-1] != t[i]) {
      ans[i] = t[i];
    }
  }
  drep(i,N) {
    if(i == N-1) {
      if(ans[i] == -1) {
        ans[i] = a[i];
      } else {
        if(ans[i] > a[i]){
          cout << 0 << endl;
          return 0;
        }
      }
    } else {
      if(a[i] == a[i+1]) continue;
      if(ans[i] == -1) {
        if(t[i] < a[i]) {
          cout << 0 << endl;
          return 0;
        } else {
          ans[i] = a[i];
        }

      } else {
        if(ans[i] < a[i]){
          cout << 0 << endl;
          return 0;
        }
      }
    }
  }
  ll c = 1;
  rep(i,N) {
    if(ans[i] == -1) {
      c *= min(t[i],a[i]);
    }
    c %= MOD;
  }
  cout << c << endl;
  return 0;
}
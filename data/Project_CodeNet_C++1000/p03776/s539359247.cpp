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

class Pascal {
  public:
    vv(ll) t;
    Pascal(int N) {
      t = vv(ll)(N+1,vl(N+1,0));
      rep(i,N+1) {
        rep(j,i+1) {
          if(j==0 || j==i) {
            t[i][j] = 1ll;
          } else {
            t[i][j] = t[i-1][j-1]+t[i-1][j];
          }
        }
      }
    }
    ll getCombi(int n,int k) {
      return t[n][k];
    }
};
  
int main() {
  int N,A,B;
  cin >> N >> A >> B;
  vl va(N);
  rep(i,N) {
    cin >> va[i];
  }
  sort(rng(va));
  reverse(rng(va));
  Pascal C(N);
  ll tar = va[A-1];
  int c1=0;
  rep(i,A) {
    if(va[i] == tar) c1++;
  }
  int c2 = 0;
  rep(i,N) {
    if(va[i] == tar) c2++;
  }
  if(c1==A) {
    ll ans = 0;
    srep(k,A,min(B,c2)+1) {
      ans += C.getCombi(c2,k);
    }
    double ave = va[A-1];
    cout << setprecision(16) << ave << endl;
    cout << ans << endl;
  } else {
    ll  ans = C.getCombi(c2,c1);
    double ave = 0;
    rep(i,A) {
      ave += 1.0 * va[i] / A;
    }
    cout << setprecision(16) << ave << endl;
    cout << ans << endl;
  }
  return 0;
}
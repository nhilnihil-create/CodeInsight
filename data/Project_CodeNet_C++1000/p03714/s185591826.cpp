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
  
int main() {
  int N;
  cin >> N;
  vi A(3*N);
  rep(i,3*N) {
    cin >> A[i];
  }
  priority_queue<int,vi,greater<int>> fir;
  ll f = 0;
  rep(i,N) {
    fir.push(A[i]);
    f += A[i];
  }
  vl ma(N+1,0);
  ma[0] = f;
  srep(i,N,2*N) {
    fir.push(A[i]);
    f += A[i];
    f -= fir.top();
    fir.pop();
    ma[i-N+1] = f;
  }
  priority_queue<int> sec;
  ll s = 0;
  rep(i,N) {
    sec.push(A[i+2*N]);
    s += A[i+2*N];
  }
  vl mi(N+1,0);
  mi[N] = s;
  for(int i = 2*N-1;i >= N;i--) {
    sec.push(A[i]);
    s += A[i];
    s -= sec.top();
    sec.pop();
    mi[i-N] = s;
  }
  ll ans = -LINF;
  rep(i,N+1) {
    ans = max(ans,ma[i]-mi[i]);
  }
  cout << ans << endl;
  return 0;
}
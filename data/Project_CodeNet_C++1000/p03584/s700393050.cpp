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
  int N,K;
  cin >> N >> K;
  vp ab(N);
  rep(i,N) {
    cin >> ab[i].first >> ab[i].second;
  }
  int b = 0;
  int tmp = K;
  while(tmp>0) {
    tmp = tmp>>1;
    b++;
  }
  ll ans = 0;
  srep(d,-1,b) {
    int tar = 0;
    rep(i,d) {
      tar += (1<<i);
    }
    srep(i,d+1,b) {
      if((K>>i)&1) {
        tar += (1<<i);
      }
    }
    if(tar>K) continue;
    ll cnt = 0;
    rep(i,N) {
      if((ab[i].first|tar)==tar) {
        cnt += ab[i].second;
      }
    }
    ans = max(ans,cnt);
  }
  cout << ans << endl;
  return 0;
}
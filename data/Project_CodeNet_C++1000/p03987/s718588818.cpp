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

class BIT {
public:
  int N;
  vi arr;
  BIT(int n) {
    N = n;
    arr = vi(N+1,0);
  }
  int sum(int x) {
    int s = 0;
    for(int i = x+1;i > 0;i -=i&(-i)) {
      s += arr[i];
    }
    return s;
  }
  void add(int x,int k) {
    for(int i = x+1;i <= N;i +=i&(-i)) {
      arr[i] += k;
    }
  }
};
  
int main() {
  int N;
  cin >> N;
  vi A(N);
  vi pos(N);
  rep(i,N) {
    cin >> A[i];
    A[i]--;
    pos[A[i]]=i;
  }
  BIT bit(N+3);
  bit.add(1,1);
  bit.add(N+2,1);
  auto incc = [&](int k) {
    bit.add(k+2,1);
  };
  auto isDiff = [&](int a,int b) {
    return bit.sum(a+1) != bit.sum(b+1);
  };
  ll ans = 0;
  rep(i,N) {
    int now = pos[i];
    int res = 0;
    int l,r;
    {
      int ng=-1,ok=now;
      while(ng+1<ok) {
        int m = (ng+ok)/2;
        if(isDiff(m,now)) {
          ng=m;
        } else {
          ok=m;
        }
      }
      l = now-ok;
    }
    {
      int ok=now,ng=N+1;
      while(ok+1<ng) {
        int m = (ok+ng)/2;
        if(isDiff(now,m)) {
          ng=m;
        } else {
          ok=m;
        }
      }
      r = ok-now-1;
    }
    incc(now);
    ans += ll(i+1)*(l+1)*(r+1);
  }
  cout << ans << endl;

  return 0;
}
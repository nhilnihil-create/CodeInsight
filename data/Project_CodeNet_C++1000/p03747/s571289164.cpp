#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<ll> fac;
void c_fac(int x=pow(10,6)+10) { fac.resize(x,true); rep(i,x) fac[i] = i ? (fac[i-1]*i)%MOD : 1; }
ll inv(ll a, ll m=MOD) { ll b = m, x = 1, y = 0; while (b!=0) { int d = a/b; a -= b*d; swap(a,b); x -= y*d; swap(x,y); } return (x+m)%m; }
ll nck(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%MOD)%MOD; }
ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

struct ant { ll X; ll W; };

int main() {
  ll N, L, T; cin >> N >> L >> T;
  ant a[N]; rep(i,N) { ll X, W; cin >> X >> W; a[i] = {X,W}; }
  ll pos[N]; rep(i,N) pos[i] = ((a[i].X+T*(a[i].W==1?1:-1))%L+L)%L;

  if (N==1) { cout << pos[0] << endl; return 0; }

  ll count0 = 0;
  rep(i,N) {
    if (a[0].W!=a[i].W)  {
      ll diff;
      if (a[0].W==1) diff = (L-(a[i].X-a[0].X+L)%L) + 2*T;
      else diff = (L-(a[0].X-a[i].X+L)%L) + 2*T;
      count0 += diff/L;
      count0 %= N;
    }
  }
  ll p0 = a[0].W==1 ? count0 : (N-count0)%N;
  // cout << p0 << endl; debug(pos,pos+N);

  ll result[N] = {}; result[p0] = pos[0];
  ll tp = pos[1];
  sort(pos,pos+N);
  int p;
  if (a[0].W==1) p = upper_bound(pos,pos+N,result[p0]) - pos - 1;
  else p = lower_bound(pos,pos+N,result[p0]) - pos;
  rep(i,N) result[(p0+i)%N] = pos[(p+i)%N];
  rep(i,N) cout << result[i] << endl;
  return 0;
}
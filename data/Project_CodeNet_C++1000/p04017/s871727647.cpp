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

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

int ln2 = 0;
vector<vector<int>> adj;
vector<vector<ll>> par;
vector<ll> rnk;
 
void calc_parent(int n) { rep(i,ln2) rep(j,n) if (rnk[j]>=powl(2,i+1)) par[j][i+1] = par[par[j][i]][i]; }
void calc_rnk(int n=0, int p=-1) { if (p==-1) rnk[n]=0; for (auto x: adj[n]) { if (x!=p) { rnk[x] = rnk[n]+1; par[x][0] = n; calc_rnk(x,n); } } }
void init_lca() { int n=adj.size();  while(n>=(1<<ln2)) ln2++; par.resize(n,vector<ll>(ln2,-1)); rnk.resize(n); calc_rnk(); calc_parent(n); }
bool large(int u, int v) { if (rnk[u]<rnk[v]) swap(u,v); int diff = rnk[u]-rnk[v]; int b_pos = 0; while(diff>=(1ull<<b_pos)) { if (diff&(1ull<<b_pos)) u = par[u][b_pos]; b_pos++; } return u>v; }

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

int main() {
  int N; cin >> N;
  ll x[N]; rep(i,N) cin >> x[i];
  ll L; cin >> L;
  adj.resize(N);
  repr(i,1,N) {
    auto par = lower_bound(x,x+N,x[i]-L);
    adj[par-x].push_back(i);
    // cout << x[i] << " " << parp-x << endl;
  }

  init_lca();
  // debug(all(rnk));

  int Q; cin >> Q;
  rep(i,Q) {
    int a, b; cin >> a >> b; a--; b--;
    if (a<b) swap(a,b); 
    int result = large(a,b) ? rnk[a]-rnk[b]+1 : rnk[a]-rnk[b];
    cout << result << endl;
  }
  return 0;
}
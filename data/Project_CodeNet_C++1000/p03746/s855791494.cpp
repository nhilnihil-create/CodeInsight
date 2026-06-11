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

vector<int> par;
vector<bool> used;
vector<vector<int>> adj;
int last;

void dfs(int n) {
  bool islast = true;
  for (auto x: adj[n]) {
    if (used[x]) continue;
    else {
      used[x] = true; islast = false;
      if (par[n]==-1) par[n] = x;
      else par[x] = n;
      dfs(x);
      break;
    }
  }
  if (islast) last = n;
}

int main() {
  int N, M; cin >> N >> M;
  par.resize(N,-1); used.resize(N,false); adj.resize(N);
  int p1, p2;
  rep(i,M) {
    int A, B; cin >> A >> B; A--; B--;
    adj[A].push_back(B); adj[B].push_back(A);
    if (i==0) { p1 = A; p2 = B; }
  }
  par[p1] = p2; used[p1] = true; used[p2] = true;
  dfs(p2); dfs(p1);
  // debug(all(par)); cout << last << endl;
  vector<int> result;
  while (last!=-1) {
    result.push_back(last+1);
    last = par[last];
  }
  cout << result.size() << endl;
  debug(all(result));
  return 0;
}
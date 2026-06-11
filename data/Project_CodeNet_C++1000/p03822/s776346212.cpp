#include<bits/stdc++.h>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define rrep(i,a) for(int i=(int)a-1;i>=0;--i)
#define REP(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RREP(i,a,b) for(int i=(int)a-1;i>=b;--i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


ll gcd(ll n, ll m) {
    ll tmp;
    while (m!=0) {
        tmp = n % m;
        n = m;
        m = tmp;
    }
		return n;
}

ll lcm(ll n, ll m) {
    return abs(n) / gcd(n, m)*abs(m);//gl=xy
}

using namespace std;

vector<vector<int>> g;
vector<int> d;

int dfs(int v){
  int res = 0;
  vector<int> s;
  for (auto x : g[v])
  {
    s.pb(dfs(x));
  }
  if(!s.empty()){
    sort(rall(s));
    rep(i, s.size()) s[i] += i + 1;
    res = *max_element(all(s));
  }
  return d[v] = res;
}

void solve()
{
	int n;
	cin >> n;
  vector<int> a(n-1);
  rep(i, n-1) cin >> a[i];
  g.resize(n);
  rep(i,n-1){
    a[i]--;
    g[a[i]].eb(i+1);
  }
  d.resize(n);
  dfs(0);
  cout << d[0]<< endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);
    solve();
    return 0;
}

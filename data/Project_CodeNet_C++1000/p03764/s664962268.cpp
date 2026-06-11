#include <bits/stdc++.h>
 
using namespace std;

#define M 1000000007
#define pb emplace_back
#define f first
#define s second
#define rep(i, st, ed) for(ll i=st; i<ed; ++i)
#define repn(i, st, ed) for(ll i=st; i<=ed; ++i)
#define repb(i, ed, st) for(ll i=ed; i>=st; --i)
#define all(v) v.begin(),v.end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define PI acosl(-1.0)
#define mp(a, b) make_pair(a, b)

typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vec;
typedef vector<pll> vecp;
typedef map<ll, ll> mpll;


const int N = 1e5 + 10;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << to_string(H) << endl;
  debug_out(T...);
}
#define LOCAL 3
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:" << endl, debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif


void solve()
{
    ll n, m;
    cin>>n>>m;
    vector<ll> x(n), y(m);
    ll ans = 0;
    rep(i, 0, n) cin>>x[i];
    rep(i, 0, m) cin>>y[i];
    sort(all(x));
    sort(all(y));
    ll xans = 0;
    rep(i, 1, n)
    {
    	xans = (xans + (((abs(x[i] - x[i-1]) * (i)) % M) * (n-i)) % M ) % M;
    	while(xans < 0) xans += M;
    }
    //cout<<xans<<endl;
    ll yans = 0;
    rep(i, 1, m)
    {
    	yans = (yans + (((abs(y[i] - y[i-1]) * i) % M) * (m-i)) % M ) % M;
    	while(yans < 0) yans += M;
    }
    //cout<<yans<<endl;
    ans = (xans*yans)%M;
    cout<<ans<<endl;
}


int main()
{
    ll Tests = 1;
    //cin>>Tests;
    while(Tests--)
    {
        solve();
    }
    return 0;
}
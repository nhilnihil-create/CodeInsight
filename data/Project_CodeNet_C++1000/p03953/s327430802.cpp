#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORR(i,a,b) for (int i=(a);i>=(b);i--)
#define pb push_back
#define pcnt __builtin_popcount
#define show(x) cout<<#x<<" = "<<x<<endl;
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define fi first
#define se second
#define rng(a) (a.begin()),(a.end())
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define sz(x) (int)(x).size()
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef set<int> si;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vpll;
typedef set<ll> sl;
typedef __int128_t lll;
typedef pair<lll,lll> plll;
typedef vector<lll> vlll;
template<typename T>string join(vector<T>&v)
{stringstream s;FOR(i,0,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename A, size_t N, typename T>void Fill(A (&array)[N], const T&v)
{fill((T*)array,(T*)(array+N),v);}
ll gcd(ll a,ll b){if(a>b)swap(a,b);for(;a>0;b%=a,swap(a,b));return b;}
int modpow(ll a,ll n,int m){if(a==0)return a;ll p=1;for(;n>0;n/=2,a=a*a%m)if(n&1)p=p*a%m;return(int)p;}
void dout(double d){printf("%.12f\n",d);}

const int iinf = 1e9;
const ll linf = 1e18;
const int mod = 1e9+7;
const double pi = acos(-1);
const double eps = 1e-10;
const int N = 1e5;
int n, x, m;
vi a, b, t, d;
ll k, p;
void merge(vi&x, vi&y, vi&z){
  FOR(i, 0, n-1) t[i] = y[x[i]];
  FOR(i, 0, n-1) z[i] = t[i];
}
main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> x;
  p = x;
  FOR(i, 0, n-1){
    int _x;
    cin >> _x;
    d.pb(_x-x);
    x = _x;
    a.pb(i);
    b.pb(i);
  }
  t.resize(n-1);
  cin >> m >> k;
  FOR(i, 0, m){
    int s;
    cin >> s;
    swap(a[s-2], a[s-1]);
  }
  while(k > 0){
    if(k%2) merge(b, a, b);
    merge(a, a, a);
    k >>= 1;
  }
  FOR(i, 0, n){
    printf("%lld\n", p);
    if(i == n-1) break;
    p += d[b[i]];
  }
  return 0;
}
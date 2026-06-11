#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)  for(int i=(a),i##formax=(b);i< i##formax;i++)
#define FORR(i,a,b) for(int i=(a),i##formin=(b);i>=i##formin;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pcnt __builtin_popcount
#define sz(x) (int)(x).size()
#define maxs(x,y) x=max((x),(y))
#define mins(x,y) x=min((x),(y))
#define show(x) cout<<#x<<" = "<<(x)<<endl;
#define all(a) ((a).begin()),((a).end())
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define bit(n) (1LL<<(n))
typedef long long ll;
typedef __int128_t lll;
template<class T>using V=vector<T>;
template<class T>using VV=V<V<T>>;
template<class T>ostream& operator<<(ostream&o,V<T>&v){for(T&t:v)o<<t<<",";return o<<endl;}
template<class T>void uniq(V<T>&v){sort(all(v));v.erase(unique(all(v)), v.end());}

lll gcd(lll a,lll b,lll&x,lll&y){if(!b){x=1;y=0;return a;}lll d=gcd(b,a%b,y,x);y-=a/b*x;return d;}
ll modInv(ll a,ll m){lll x,y;gcd(a,m,x,y);return(x%m+m)%m;}
ll modPow(lll a,lll n,ll m){lll p=1;for(;n;n>>=1,a=a*a%m)if(n&1)p=p*a%m;return p;}
//V<ll>F,R;void setF(int n,int mod){F=R=V<ll>(++n);F[0]=1;FOR(i,1,n)F[i]=F[i-1]*i%mod;R[n-1]=modInv(F[n-1],mod);FORR(i,n-1,1)R[i-1]=R[i]*i%mod;}
//ll comb(int a,int b,int m){return a<b||b<0?0:F[a]*R[b]%m*R[a-b]%m;}

const int IINF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7; //99844353;
const int N = 1e5;
void YN(bool z){cout << (z ? "YES" : "NO") << endl; exit(0);}
int n;
ll c[N];
V<int> e[N];
ll dfs(int a, int p){
  if(sz(e[a])==1) return c[a];
  ll s = 0, ma = -1;
  for(int b:e[a]) if(p!=b){
    ll t = dfs(b, a);
    s += t;
    maxs(ma, t);
  }
  if(c[a]<max(ma, s-s/2) || s<c[a]) YN(false);
  return c[a]*2-s;
}
main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  FOR(i, 0, n) cin >> c[i];
  FOR(i, 0, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    e[a].pb(b);
    e[b].pb(a);
  }
  if(n==2) YN(c[0]==c[1]);
  FOR(i, 0, n) if(sz(e[i])>1) YN(!dfs(i, -1));
}
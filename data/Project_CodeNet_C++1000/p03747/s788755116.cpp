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
template<class T,class Y>using P=pair<T,Y>;
template<class T,class Y>ostream& operator<<(ostream&o,P<T,Y>&p){return o<<"("<<p.fi<<","<<p.se<<")";}
template<class T>ostream& operator<<(ostream&o,V<T>&v){for(T&t:v)o<<t<<",";return o<<endl;}
template<class T>void uniq(V<T>&v){sort(all(v));v.erase(unique(all(v)), v.end());}

lll gcd(lll a,lll b,lll&x,lll&y){if(!b){x=1;y=0;return a;}lll d=gcd(b,a%b,y,x);y-=a/b*x;return d;}
ll modInv(ll a,ll m){lll x,y;gcd(a,m,x,y);return(x%m+m)%m;}
ll modPow(lll a,lll n,ll m){lll p=1;for(;n;n>>=1,a=a*a%m)if(n&1)p=p*a%m;return p;}

const int IINF = 1e9+6;
const ll LINF = 1e18;
const int MOD = 1e9+7; //998244353;
const int N = 1e5;
int n, L, T, c=-1, t;
V<int> XL, XR;

main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> L >> T;
  FOR(i, 0, n){
    int x, w;
    cin >> x >> w;
    (w==1 ? XR : XL).pb(x);
    if(w==1 && c<0){
      c = i;
      t = x;
    }
  }
  if(c < 0){
    for(int a:XL) cout << ((a-T)%L+L)%L << endl;
    return 0;
  }
  c += T/L*sz(XL)*2;
  T %= L;
  for(int a:XL){
    if((a-t+L)%L   < T*2) c++;
    if((a-t+L)%L+L < T*2) c++;
  }
  c %= n;
  V<int> v;
  for(int a:XR) v.pb((a+T)%L);
  for(int a:XL) v.pb((a+L-T)%L);
  sort(all(v));
  int i = lower_bound(all(v), (t+T)%L) - v.begin();
  i = (i+n-c)%n;
  FOR(_, 0, n){
    cout << v[i] << endl;
    i = (i+1)%n;
  }
}
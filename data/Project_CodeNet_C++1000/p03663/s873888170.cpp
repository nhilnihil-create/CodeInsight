#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)  for(int i=(a),i##formax=(b);i< i##formax;i++)
#define FORR(i,a,b) for(int i=(a),i##formin=(b);i>=i##formin;i--)
#define pb push_back
#define eb emplace_back
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
template<class T>ostream& operator<<(ostream&o,V<T>&v){for(T&t:v)o<<t<<",";return o;}
template<class T>void uniq(V<T>&v){sort(all(v));v.erase(unique(all(v)), v.end());}

lll gcd(lll a,lll b,lll&x,lll&y){if(!b){x=1;y=0;return a;}lll d=gcd(b,a%b,y,x);y-=a/b*x;return d;}
ll modInv(ll a,ll m){lll x,y;gcd(a,m,x,y);return(x%m+m)%m;}
ll modPow(lll a,lll n,ll m){lll p=1;for(;n;n>>=1,a=a*a%m)if(n&1)p=p*a%m;return p;}
V<ll>Fac,Rac;void setF(int n,int mod){Fac=Rac=V<ll>(++n);Fac[0]=1;FOR(i,1,n)Fac[i]=Fac[i-1]*i%mod;Rac[n-1]=modInv(Fac[n-1],mod);FORR(i,n-1,1)Rac[i-1]=Rac[i]*i%mod;}
ll comb(int a,int b,int m){return a<b||b<0?0:Fac[a]*Rac[b]%m*Rac[a-b]%m;}

const int IINF = 1e9+6;
const ll LINF = 1e18;
const int MOD = 1e9+7; //998244353;
bool ask(ll a){
  cout << "? " << a << endl << flush;
  string s;
  cin >> s;
  return s[0]=='Y';
}
void ans(ll a){
  cout << "! " << a << endl << flush;
  exit(0);
}
main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  if(ask(1e10)){
    ll a = 1e9;
    FOR(_, 0, 9){
      if(!ask(a-1)) ans(a);
      a /= 10;
    }
    ans(1);
  }
  ll l, r, m;
  l=0;
  r=9;
  while(r-l>1){
    m = (l+r)/2;
    if(ask(modPow(10, m, LINF))){
      l = m;
    }else{
      r = m;
    }
  }
  l = modPow(10, l, LINF);
  r = l*10;
  while(r-l>1){
    m = (l+r)/2;
    if(!ask(m*10)){
      l = m;
    }else{
      r = m;
    }
  }
  ans(r);
}
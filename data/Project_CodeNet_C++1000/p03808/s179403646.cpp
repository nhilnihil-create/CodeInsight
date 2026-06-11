#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using ld = long double;
template<typename T> using V = vector<T>;
template<typename T> using VV = vector<vector<T>>;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,a,n) for(ll i=a;i<(ll)(n);++i)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;--i)
#define ENDL '\n'
typedef pair<int,int> Pi;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 +99);
const vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
template<typename T,typename U> inline bool chmin(T& t, const U& u){if(t>u){t=u;return 1;}return 0;}
template<typename T,typename U> inline bool chmax(T& t, const U& u){if(t<u){t=u;return 1;}return 0;}
template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T,typename Y> inline T mpow(T a, Y n) {
  T res = 1;
  for(;n;n>>=1) {
    if (n & 1) res = res * a;
    a = a * a;
  }
  return res;
}

void no(){
  cout<<"NO"<<ENDL;
  exit(0);
}

signed main(){
  cin.tie(0);ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  ll n;cin>>n;
  ll sum=0,num;
  V<ll> v(n),dif(n);
  rep(i,0,n){
    cin>>v[i];
    sum+=v[i];
  }
  rep(i,0,n)dif[i]=v[(i+1)%n]-v[i];

  if(sum%((n*(n+1))/2ll)!=0){
    no();
  }else{
    num=sum/((n*(n+1))/2ll);
  }

  ll x,cnt=0;
  rep(i,0,n){
    x=(num-dif[i]);
    if(dif[i]>num)no();

    if((x+n*INF)%n!=0)no();
    else {
      cnt+=x/n;
    }
  }

  if(num==cnt)cout<<"YES"<<ENDL;
  else cout<<"NO"<<ENDL;
}
//( ・ __ ・ ) KEEP BEING ORGANIZED
//CHECK overflow,vector_size,what to output?
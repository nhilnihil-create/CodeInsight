#include<bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using vt = vector<T>;
template<class T> using vvt = vector<vt<T>>;
template<class T> using ttt = tuple<T,T>;
using tii = tuple<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define mt make_tuple
#define ALL(a) (a).begin(),(a).end()
#define FST first
#define SEC second
#define DEB cerr<<"!"<<endl
#define SHOW(a,b) cerr<<(a)<<" "<<(b)<<endl
#define DIV int(1e9+7)
const int INF = (INT_MAX/2);
const ll LLINF = (LLONG_MAX/2);
const double eps = 1e-8;
//const double PI = M_PI;  
inline ll pow(ll x,ll n,ll m){ll r=1;while(n>0){if((n&1)==1)r=r*x%m;x=x*x%m;n>>=1;}return r%m;}
inline ll lcm(ll d1, ll d2){return d1 / __gcd(d1, d2) * d2;}
/* Coding space */
int main(){
  ll k; cin >> k;
  cout << 50 << endl;
  vector<ll> ans(50);
  rep(i,50) ans[i] = (49-i) + (k / 50);
  rep(i,k%50) ans[i]++;
  
  rep(i,50){
    cout << ans[i] << (i == 49?"\n":" ");
  }
}
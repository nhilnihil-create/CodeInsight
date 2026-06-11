#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define lfs <<fixed<<setprecision(10)<<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = n; i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = n - 1; i >= (ll)(m); i--)
using ll = long long;
using ld = long double;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T>
void chmin(T &a,T b){if(a>b)a=b;}
template<typename T>
void chmax(T &a,T b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void pmod(ll &a,ll b,ll c){a=(b+c)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void qmod(ll &a,ll b,ll c){a=(b*c)%MOD;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>
void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>
void debug(vector<vector<T>>v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>
void debug(vector<T>v,ll n){cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>
vector<vector<T>>vec(ll x, ll y, T w){
  vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
template<typename T>
void emp(map<T,ll>&m, T x){m.emplace(x,0).first->second++;}
vector<ll>dx={1,0,-1,0,1,1,-1,-1};
vector<ll>dy={0,1,0,-1,1,-1,1,-1};
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

ll MAX_V = 2e5 + 5;
vector<vector<ll>> G(MAX_V);//隣接リスト(添え字は始点、値は終点)
vector<ll>t(MAX_V);//訪問したかどうか
void dfs(ll k){
  t[k]=1;
  for(ll i=0;i<G[k].size();i++){
    if(t[G[k][i]]==0){
      dfs(G[k][i]); 
    }
  }
}

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  map<ll,ll>mp;
  rep(i,0,n){
    ll x;cin>>x;
    emp(mp,x);
  }
  vector<ll>a(m),b(m);
  for(auto z:mp){
    a[z.fi%m]+=z.se%2;
    b[z.fi%m]+=z.se/2;
  }
  rep(i,0,m/2+1){
    if(i==(m-i)%m){
      res+=a[i]/2+b[i];
    }
    else{
      ll k=(m-i)%m;
      res+=min(a[i],a[k]);
      if(a[i]<=a[k]){
        ll x=a[k]-a[i];
        res+=b[k];
        if(x>=2*b[i])res+=2*b[i];
        else res+=x+(2*b[i]-x)/2;
      }
      else{
        ll x=a[i]-a[k];
        res+=b[i];
        if(x>=2*b[k])res+=2*b[k];
        else res+=x+(2*b[k]-x)/2;
      }
    }
    //cout<<i spa res<<endl;
  }
  cout<<res<<endl;
  return 0;
}
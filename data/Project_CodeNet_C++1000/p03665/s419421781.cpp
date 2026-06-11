#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
ll gcd(ll a,ll b){if(a%b==0){return b;}else{return(gcd(b,a%b));}}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
const double PI=acos(-1);
 
int main() { //  1 1 1 2 2 2
  ll n,p;
  cin>>n>>p;
  vi a(n);
  int cnt=0;
  ll ans;
  rep(i,n){
    cin>>a[i];
    if(a[i]%2==0) cnt++;
  }
  if(cnt==n){
    if(p==0){
      ans=pow(2,n);
      cout<<ans<<endl;
      return 0;
    }
    if(p==1){
      cout<<0<<endl;
      return 0;
    }
  }
  ans=pow(2,n-1);
  cout<<ans<<endl;
}
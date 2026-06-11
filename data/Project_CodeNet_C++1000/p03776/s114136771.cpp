#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll dp[62][62];
void make(){
    dp[0][0]=1;
    for(int i=1;i<52;i++){
        dp[i][0]=dp[i-1][0];
        for(int j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }
}
int main(){
    make();
  ll n,a,b;
  cin>>n>>a>>b;
  V<ll> d(n);
  for(int i=0;i<n;i++)cin>>d[i];
  sort(all(d),greater<ll>());
  ll sum=0;
  for(int i=0;i<a;i++)sum+=d[i];
  cout<<double(sum)/double(a)<<"\n";
  ll c=d[0],cnt=0,rem=a;
  ll t=a;
  for(int i=0;i<n;i++){
      if(d[i]==c){
          cnt++;
          a--;
      }else{
          if(a<=0)break;
          rem=a;
          cnt=1;
          c=d[i];
          a--;
      }
  }
  ll ans=0;
  if(rem==t){
  for(int i=rem;i<=min(cnt,b);i++){
      ans+=dp[cnt][i];
      //cout<<ans<<"\n";
     }
  }else ans=dp[cnt][rem];
  cout<<ans<<"\n";
}
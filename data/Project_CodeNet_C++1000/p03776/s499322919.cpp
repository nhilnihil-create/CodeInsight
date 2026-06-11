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
int GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll dp[55][55];
void init(){
 for(int i=0;i<=52;i++)dp[i][i]=1;
for(int i=0;i<=52;i++){
    dp[i+1][0]=dp[i][0];
    for(int j=1;j<i+1;j++){
        dp[i+1][j]=dp[i][j-1]+dp[i][j];
    }
}
}
int main(){
  int n,a,b;
  cin>>n>>a>>b;
  init();
  V<double> d(n);
  for(int i=0;i<n;i++)cin>>d[i];
  sort(all(d),greater<double>());
  double sum=0;
  for(int i=0;i<a;i++)sum+=d[i];
  cout<<sum/a<<"\n";
  dp[0][0]=1;
  int cnt=0,cn;
  for(int i=0;i<n;i++){
    if(d[i]==d[a-1])cnt++;
    if(d[i]>d[a-1])cn++;
  }
  ll ans=0;
  if(d[0]==d[a-1]){
    for(int i=a;i<=b;i++)ans+=dp[cnt][i];
  }
    else ans+=dp[cnt][a-cn];
  cout<<ans<<"\n";
}
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),v.end()
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll dp[51][51];
int main(){
  int n,a,b;
  cin>>n>>a>>b;
  vector<double> s(n);
  for(int i=0;i<n;i++)cin>>s[i];
  sort(all(s),greater<double>());
  double sum=0.0;
  for(int i=0;i<a;i++)sum+=s[i];
  printf("%.8f\n",sum/(double)a);
  for(int i=0;i<=n;i++)dp[i][i]=1;
  for(int i=0;i<n;i++){
    dp[i+1][0]=1;
    for(int j=1;j<i+1;j++){
      dp[i+1][j]=dp[i][j-1]+dp[i][j];
      }
   }
     ll cnt=0,cn=0;
     for(int i=0;i<n;i++){
     if(s[a-1]==s[i]){
            cnt++;
            if(i<a)cn++;
            }
            }
      if(s[0]==s[a-1]){
        ll ans=0;
        for(int i=a;i<=b;i++)ans+=dp[cnt][i];
        cout<<ans<<endl;
        }
        else cout<<dp[cnt][cn]<<endl;
     
      
}

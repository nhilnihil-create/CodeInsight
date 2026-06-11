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
int main(){
   ll n,x;
   cin>>n>>x;
   vector<ll> a(n),b(n);
   for(int i=0;i<n;i++){
       cin>>a[i];
       b[i]=a[i];
   }
   ll ans=inf;
   //色変の操作回数kを固定して求める
   for(int k=0;k<n;k++){
       ll change=k*x;
       //i~i-k区間の最小値をとる
       ll sum=0;
       for(int i=0;i<n;i++){
           b[i]=min(b[i],a[(i+n-k)%n]);
           sum+=b[i];
       }
       ans=min(ans,sum+change);
       }
   cout<<ans<<endl;
}
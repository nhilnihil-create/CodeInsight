#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define PI acos(-1)
typedef  long long ll;
ll MOD=1000000007;
ll gcd(ll x,ll y){
   if(y==0) return x;
   else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
   return x/gcd(x,y)*y;
}

int main(){
   int n,m;
   cin>>n>>m;
   ll ans=1;

   if(abs(n-m)==1){
      for(int i=1;i<=n;i++){
         ans*=i;
         ans%=MOD;
      }
      for(int i=1;i<=m;i++){
         ans*=i;
         ans%=MOD;
      }
   }
   else if(n-m==0){
      for(int i=1;i<=n;i++){
         ans*=i;
         ans%=MOD;
      }
      for(int i=1;i<=m;i++){
         ans*=i;
         ans%=MOD;
      }
      ans*=2;
      ans%=MOD;
   }
   else ans=0;
   
   cout<<ans;

   return 0;
}

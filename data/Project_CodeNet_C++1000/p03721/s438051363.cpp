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
   ll n,k;
   cin>>n>>k;
   
   ll r[100001];

   rep(i,100001){
      r[i]=0;
   }
   rep(i,n){
      ll a,b;
      cin>>a>>b;
      r[a]+=b;
   }
   ll ans=0;
   rep(i,100001){
      ans+=r[i];
      if(ans>=k){
         cout<<i;
         break;
      }
   }
   
   return 0;
}

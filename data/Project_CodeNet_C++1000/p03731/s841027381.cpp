#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define PI acos(-1)
typedef  long long ll;
ll gcd(ll x,ll y){
   if(y==0) return x;
   else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
   return x/gcd(x,y)*y;
}
using namespace std;

int main(){
   ll n,t;
   cin>>n>>t;
   vector<ll> a(n,0);
   rep(i,n){
      cin>>a[i];
   }
   ll ans=0;
   ll now=0;
   rep(i,n-1){
      ll x=min(t,(a[i+1]-now));
      ans+=x;
      if(x==t) now=a[i+1];
      else now+=x;

      
   }
   ans+=t;
   cout<<ans;
return 0;
}


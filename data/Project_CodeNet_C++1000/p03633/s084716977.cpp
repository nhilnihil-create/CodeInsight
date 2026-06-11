#include<bits/stdc++.h>
using namespace std;
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

int main(){
   int n;
   cin>>n;

   ll ans;
   cin>>ans;

   rep(i,n-1){
      ll x;
      cin>>x;

      ans=lcm(ans,x);
   }
   cout<<ans;
   return 0;
}

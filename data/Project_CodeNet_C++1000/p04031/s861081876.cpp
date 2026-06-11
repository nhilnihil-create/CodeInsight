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
   
   int n;
   cin>>n;
   vector<int> a(n);

   rep(i,n){
      cin>>a[i];
   }

   int ans=10000000;
   int cnt=0;
   for(int i=-100;i<=100;i++){
      rep(j,n){
         cnt+=pow((i-a[j]),2);
      }
      ans=min(ans,cnt);
      cnt=0;
   }

   cout<<ans;
   return 0;
}

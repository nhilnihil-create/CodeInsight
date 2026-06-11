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
   
   string s;
   cin>>s;

   int x=s.size();

   int cnt=0;
   char c=s[0];

   rep(i,x){
      if(s[i]!=c){
         cnt++;
         c=s[i];
      }
   }

   cout<<cnt;
   return 0;
}

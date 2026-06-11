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
   ll x;
   cin>>x;
   ll i=2.0*x/11.0;
   
   if(x%11==0){}
   else if(x%11>6) i++;  
   else if(x%11<6) i++;
   cout<<i;

   return 0;
}

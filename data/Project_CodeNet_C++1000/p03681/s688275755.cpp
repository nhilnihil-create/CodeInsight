#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const long long INF = 1LL << 60;
int main(){
   ll a,b;
   cin>>a>>b;
   ll mod=1000000007;
   if(abs(a-b)<=1){
       ll ans=1;
       rrep(i,a){
           ans*=i;
           ans%=mod;
       }
       rrep(i,b){
           ans*=i;
           ans%=mod;
       }
     	if(a==b){
          ans*=2;
        }
       cout<<ans%mod<<endl;
   }
   else{
       cout<<0<<endl;
   }
}


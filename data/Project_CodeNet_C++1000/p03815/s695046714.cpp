#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main(void){
   long long x;
   cin>>x;
   long long ans=x/11;
   ans*=2;
   if(x<=6){
      cout<<1<<endl;
   }else{
      if(x%11==0){
         cout<<ans<<endl;
      }else if(1<=x%11&&x%11<=6){
         cout<<ans+1<<endl;
      }else{
         cout<<ans+2<<endl;
      }
   }
   return 0;
}
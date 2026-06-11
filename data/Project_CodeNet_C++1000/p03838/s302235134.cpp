#include<bits/stdc++.h>
using namespace std;

int main(void){
   long long x,y;
   cin>>x>>y;
   long long ans=0;
   if(x<0&&y>0){
      ans+=1;
      x=x*(-1);
      if(x>y){
         ans=0;
         ans+=(x-y);
         ans+=1;
         cout<<ans<<endl;
      }else{
         ans+=(y-x);
         cout<<ans<<endl;
      }
   }else if(x>0&&y>0){
      if(x>y){
         ans+=1;
         ans+=(x-y);
         ans+=1;
         cout<<ans<<endl;
      }else{
         ans+=(y-x);
         cout<<ans<<endl;
      }
   }else if(x<0&&y<0){
      if(x>y){
         ans+=1;
         ans+=(x-y);
         ans+=1;
         cout<<ans<<endl;
      }else{
         ans+=(y-x);
         cout<<ans<<endl;
      }
   }else if(x>0&&y<0){
      ans+=1;
      x=x*(-1);
      if(x>y){
         ans=0;
         ans+=(x-y);
         ans+=1;
         cout<<ans<<endl;
      }else{
         ans+=(y-x);
         cout<<ans<<endl;
      }
   }else if(y==0){
      if(x<y){
         cout<<y-x<<endl;
      }else{
         cout<<x-y+1<<endl;
      }
   }else if(x==0){
      if(x<y){
         cout<<y-x<<endl;
      }else{
         cout<<x-y+1<<endl;
      }
   }
   return 0;
}

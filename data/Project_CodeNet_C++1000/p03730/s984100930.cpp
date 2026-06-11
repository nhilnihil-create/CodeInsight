#include <iostream>
using namespace std;

int main(void){
  int a,b,c;
  cin>>a>>b>>c;
  
  if(a%b==0){
   cout<<"NO"<<endl; 
  }else{
   int i,ans;
   for(i=1;i<=b;i++){
     ans=a*i-c;
     if(ans%b==0){
      cout<<"YES"<<endl;
 	  break;
     }
   }
   if(i==b+1)cout<<"NO"<<endl;
  }
  return 0;
}
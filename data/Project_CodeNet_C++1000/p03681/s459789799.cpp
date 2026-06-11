#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long fact(long long a){
   long long result=1;
   for(int i=1;i<=a;i++){
      result*=i;
      result=result%mod;
   }
   return result;
}
int main(void){
   int N,M;
   cin>>N>>M;
   if(abs(N-M)>=2){
      cout<<0<<endl;
   }else if(abs(N-M)==1){
      cout<<fact(N)*fact(M)%mod<<endl;
   }else{
      cout<<fact(N)*fact(M)*2%mod<<endl;
   }
   return 0;
}
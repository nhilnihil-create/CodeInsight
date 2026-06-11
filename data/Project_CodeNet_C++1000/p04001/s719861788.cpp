#include<bits/stdc++.h>
using namespace std;

int main(void){
   string S;
   cin>>S;
   int N=S.size();
   long long ans=0;
   for(int bit=0;bit<(1<<(N-1));bit++){
      long long sum=0;
      for(int i=0;i<N-1;i++){
         sum*=10;
         sum+=(S[i]-'0');
         if(bit&((1<<i))){
            ans+=sum;
            sum=0;
         }
      }
      sum*=10;
      sum+=(S[N-1]-'0');
      ans+=sum;
   }
   cout<<ans<<endl;
   return 0;
}

#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(void){
   string S;
   cin>>S;
   int N=S.size();
   long long ans=0;
   for(int i=0;i<(1<<N-1);i++){
      long long sum=0;
      long long cur=0;
      for(int j=0;j<N;j++){
         if(j>0&&i&(1<<(j-1))){
            sum+=cur;
            cur=0;
         }
         cur=10*cur+(S[j]-'0');
      }
      sum+=cur;
      ans+=sum;
   }
   cout<<ans<<endl;
   return 0;
}

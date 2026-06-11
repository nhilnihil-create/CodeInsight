#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<int> s(N);
   for(int i=0;i<N;i++){
      cin>>s[i];
   }
   int sum=0;
   for(int i=0;i<N;i++){
      sum+=s[i];
   }
   int ans=-1;
   if(sum%10!=0){
      cout<<sum<<endl;
      return 0;
   }else{
      for(int i=0;i<N;i++){
         int temp=sum;
         temp=temp-s[i];
         if(temp%10==0) temp=0;
         ans=max(ans,temp);
      }
      cout<<ans<<endl;
   }
   return 0;
}


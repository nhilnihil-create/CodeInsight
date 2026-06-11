#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N,T;
   cin>>N>>T;
   vector<int> t(N);
   for(int i=0;i<N;i++){
      cin>>t[i];
   }
   int ans=T;
   for(int i=0;i<N-1;i++){
      if(t[i+1]-t[i]>=T) ans+=T;
      else ans+=(t[i+1]-t[i]); 
   }
   cout<<ans<<endl;
   return 0;
}
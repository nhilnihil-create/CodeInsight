#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<long long> A(N),B(N);
   long long mini=1000000007;
   long long maxi=0;
   for(int i=0;i<N;i++){
      cin>>A[i]>>B[i];
   }
   for(int i=0;i<N;i++){
      mini=min(mini,A[i]);
      maxi=max(maxi,A[i]);
   }
   long long ans=0;
   ans+=(mini-1);
   ans+=(maxi-mini+1);
   for(int i=0;i<N;i++){
      if(A[i]==maxi) ans+=B[i];
   }
   cout<<ans<<endl;
   return 0;
}

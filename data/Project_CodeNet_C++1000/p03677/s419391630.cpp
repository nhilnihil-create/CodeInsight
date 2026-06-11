#include<bits/stdc++.h>
using namespace std;
 
using lint=long long;

int main()
{
   int N,M; cin>>N>>M;
   vector<int> a(N);
   for(int i=0;i<N;i++) cin>>a[i],a[i]--;

   vector<lint> imos0(2*M+1),imos1(2*M+1);
   auto add=[&](int l,int r,int a,int b)
   {
      imos1[l]+=a; imos1[r+1]-=a;
      imos0[l]+=b; imos0[r+1]-=b;
   };

   for(int i=0;i<N-1;i++){
      int s=a[i],t=a[i+1];
      if(t<s) t+=M;
      add(s+1,t,-1,t+1);
      add(t+1,s+M,0,t-s);
   }
   for(int i=1;i<2*M;i++) imos0[i]+=imos0[i-1],imos1[i]+=imos1[i-1];

   lint ans=(lint)N*M;
   for(int i=0;i<M;i++){
      lint sum=(imos1[i]*i+imos0[i])+(imos1[i+M]*(i+M)+imos0[i+M]);
      ans=min(ans,sum);
   }
   cout<<ans<<endl;
   return 0;
}

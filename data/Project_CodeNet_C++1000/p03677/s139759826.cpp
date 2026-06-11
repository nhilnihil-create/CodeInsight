#include<bits/stdc++.h>
using namespace std;

using lint=long long;

int main()
{
   int N,M; cin>>N>>M;
   vector<int> a(N);
   for(int i=0;i<N;i++) cin>>a[i],a[i]--;

   vector<lint> imos0(M+1);
   vector<lint> imos1(M+1);
   auto add=[&](int l,int r,int a,int b)
   {
      // for x in [l,r] add ax+b
      if(l>r) return;
      imos1[l]+=a; imos1[r+1]-=a;
      imos0[l]+=b; imos0[r+1]-=b;
   };
   for(int i=0;i<N-1;i++){
      int s=a[i],t=a[i+1];
      if(s<t){
         add(0,s,0,t-s);
         add(s+1,t,-1,t+1);
         add(t+1,M-1,0,t-s);
      }else{
         add(0,t,-1,t+1);
         add(t+1,s,0,M+t-s);
         add(s+1,M-1,-1,M+t+1);
      }
   }
   for(int i=1;i<M;i++){
      imos0[i]+=imos0[i-1];
      imos1[i]+=imos1[i-1];
   }
   lint ans=(lint)N*M;
   for(int i=0;i<M;i++){ ans=min(ans,imos1[i]*i+imos0[i]); }
   cout<<ans<<endl;
   return 0;
}

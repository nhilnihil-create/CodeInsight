#include<bits/stdc++.h>
using namespace std;

using Lint=long long;

vector<int> mul(vector<int>& a,vector<int>& b)
{
   const int N=a.size();
   vector<int> res(N);
   for(int i=0;i<N;i++) res[i]=b[a[i]];
   return res;
}

vector<int> pow(vector<int>& p,Lint K)
{
   const int N=p.size();
   vector<int> res(N);
   for(int i=0;i<N;i++) res[i]=i;
   while(K>0){
      if(K&1) res=mul(res,p);
      p=mul(p,p); K>>=1;
   }
   return res;
}

int main()
{
   int N; cin>>N;
   vector<Lint> x(N);
   for(int i=0;i<N;i++) cin>>x[i];
   Lint M,K; cin>>M>>K;
   vector<int> a(M);
   for(int i=0;i<M;i++) cin>>a[i],a[i]--;

   const int sz=N-1;
   vector<int> d(sz);
   for(int i=0;i<sz;i++) d[i]=x[i+1]-x[i];

   vector<int> p(sz);
   for(int i=0;i<sz;i++) p[i]=i;
   for(int i=0;i<M;i++){
      swap(p[a[i]-1],p[a[i]]);
   }
   vector<int> res=pow(p,K);
   for(int i=0;i<sz;i++){
      x[i+1]=x[i]+d[res[i]];
   }
   for(int i=0;i<N;i++) cout<<x[i]<<endl;
   return 0;
}

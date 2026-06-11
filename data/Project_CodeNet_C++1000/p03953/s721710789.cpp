#include<bits/stdc++.h>
using namespace std;

using Lint=long long;

class Permutation
{
 private:
   vector<int> A;
 public:
   Permutation(int n):A(n){}
   int& operator[](int i){ return A[i]; }
   int size(){ return A.size(); }
   static Permutation I(int n){
      Permutation res(n);
      for(int i=0;i<n;i++) res[i]=i;
      return res;
   }

   Permutation& operator*=(Permutation& B){
      vector<int> C(size());
      for(int i=0;i<size();i++) C[i]=B[A[i]];
      A.swap(C);
      return *this;
   }
   Permutation operator*(Permutation& B){ return Permutation(*this)*=B; }
   Permutation pow(Lint K){
      Permutation res=Permutation::I(size());
      Permutation B=*this;
      while(K>0){ if(K&1) res*=B; B*=B; K>>=1; }
      return res;
   }
};

int main()
{
   int N; cin>>N;
   vector<int> x(N);
   for(int i=0;i<N;i++) cin>>x[i];
   int M; cin>>M;
   Lint K; cin>>K;
   vector<int> a(M);
   for(int i=0;i<M;i++) cin>>a[i],a[i]--;

   const int sz=N-1;
   vector<int> d(sz);
   for(int i=0;i<sz;i++) d[i]=x[i+1]-x[i];

   Permutation p=Permutation::I(sz);
   for(int i=0;i<M;i++){
      swap(p[a[i]-1],p[a[i]]);
   }
   p=p.pow(K);

   vector<Lint> ans(N);
   ans[0]=x[0];
   for(int i=0;i<sz;i++){
      ans[i+1]=ans[i]+d[p[i]];
   }
   for(int i=0;i<N;i++) cout<<ans[i]<<endl;
   return 0;
}

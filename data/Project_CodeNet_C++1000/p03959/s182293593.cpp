#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(N),B(N),C(N,10000000000);
  vector<bool> D(N,true);
  for(int &i:A)
    cin>>i;
  for(int &i:B)
    cin>>i;
  C[0]=A[0],C[N-1]=B[N-1];
  D[0]=false,D[N-1]=false;
  int mx=A[0];
  for(int i=1;i<N;i++){
    mx=max(mx,A[i]);
    if(A[i-1]!=A[i])
      D[i]=false;
    C[i]=min(mx,C[i]);
  }
  mx=B[N-1];
  for(int i=N-2;i>=0;i--){
    mx=max(mx,B[i]);
    if(B[i+1]!=B[i])
      D[i]=false;
    C[i]=min(mx,C[i]);
  }
  mx=C[0];
  for(int i=0;i<N;i++){
    if(!D[i])
      mx=max(mx,C[i]);
    if(mx!=A[i]){
      puts("0");
      return 0;
    }
  }
  mx=C[N-1];
  for(int i=N-1;i>=0;i--){
    if(!D[i])
      mx=max(mx,C[i]);
    if(mx!=B[i]){
      puts("0");
      return 0;
    }
  }
  int ans=1;
  for(int i=0;i<N;i++)
    if(D[i])
      ans=ans*C[i]%1000000007;
  cout<<ans<<endl;
}
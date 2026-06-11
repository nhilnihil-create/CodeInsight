#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,x;
  cin>>N>>x;
  vector<int> A(N);
  for(int &i:A)
    cin>>i;
  int j=0;
  for(int i=1;i<N;i++){
    if(A[i]+A[i-1]<x)
      continue;
    j+=A[i]+A[i-1]-x;
    A[i]=max(x-A[i-1],0LL);
  }
  cout<<j<<endl;
}
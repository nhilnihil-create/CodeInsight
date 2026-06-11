#include<bits/stdc++.h>
using namespace std;
int main(){
  long N;cin>>N;
  vector<long>P(N);for(long i=0;i<N;i++)cin>>P[i];
  vector<long>X(N,0);for(long i=0;i<N;i++)X[P[i]-1]+=i;
  
  vector<long>A(N,1),B(N,1);
  for(long i=0;i<N;i++){A[i]=i+1;B[i]=N-i;}
  
  long x=0;
  for(long i=0;i<N;i++){
    x+=X[i];
    A[i]+=x;
  }
  
  long y=0;
  for(long i=N-1;i>=0;i--){
    y+=X[i];
    B[i]+=y;
  }
  
  for(long i=0;i<N;i++)cout<<A[i]<<" ";cout<<endl;
  for(long i=0;i<N;i++)cout<<B[i]<<" ";
}
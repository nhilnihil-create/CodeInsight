#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<pair<int,int> >X(N);
  for(int i=0;i<N;i++){cin>>X[i].first;X[i].second=i+1;}
  sort(X.begin(),X.end());

  vector<int>A(N*N,-1);
  //セグ木で高速化?
  int l=0;
  for(int i=0;i<N;i++){
    A[X[i].first-1]=X[i].second;
    for(int j=0;j<X[i].second-1;j++){
      while(A[l]!=-1)l++;
      A[l]=X[i].second;
    }
    if(l>X[i].first-1){cout<<"No";return 0;}
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N-X[i].second;j++){
      while(A[l]!=-1)l++;
      if(l<X[i].first-1){cout<<"No";return 0;}
      A[l]=X[i].second;
    }
  }
  cout<<"Yes"<<endl;
  for(int i=0;i<N*N;i++)cout<<A[i]<<" ";

  

}
#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  int T[N];
  int all=0;
  for(int i=0;i<N;i++){
    cin>>T[i];
    all+=T[i];
  }
  int M;cin>>M;
  int P[M],X[M];
  for(int i=0;i<M;i++) cin>>P[i]>>X[i];
  for(int i=0;i<M;i++) cout<<all-T[P[i]-1]+X[i]<<endl;
}
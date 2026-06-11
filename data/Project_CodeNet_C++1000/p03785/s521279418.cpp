#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,C,K;
  cin>>N>>C>>K;
  vector<int> T(N);
  for(int &i:T)
    cin>>i;
  sort(T.begin(),T.end());
  int t=0,k=0;
  for(int i=0;i<N;){
    k++;
    t=T[i]+K;
    int n=i;
    for(;i<N;i++){
      if(T[i]>t || i-n==C)
        break;
    }
  }
  cout<<k<<endl;
}
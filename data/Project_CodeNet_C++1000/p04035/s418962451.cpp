#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,L;
  cin>>N>>L;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  int Z=0;
  for(int i=1;i<N;i++){
    if(p[i]+p[i-1]>=L){
      Z=i;
      break;
    }
  }
  if(Z){
    cout<<"Possible"<<endl;
    for(int i=1;i<Z;i++){
      cout<<i<<endl;                  
    }
    for(int i=N-1;i>=Z;i--){
      cout<<i<<endl;
    }
  }
  else{
    cout<<"Impossible"<<endl;
  }
}
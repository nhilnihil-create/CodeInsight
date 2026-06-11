#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,K,X,Y;
  cin>>N>>K>>X>>Y;
  if(K>=N){
    cout<<N*X<<endl;
  }
  else if(K<N){
    cout<<K*X+Y*(N-K)<<endl;
  }
}
    
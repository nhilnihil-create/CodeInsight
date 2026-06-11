#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<bool>G(N,true);
  for(int X=0;X<N;X++){
    int S;cin>>S;
    if(X+1==S){
      G[X]=false;
    }
  }
  int U=0;
  long long K=0;
  for(int X=0;X<N;X++){
    if(X!=0&&G[X]==true&&G[X-1]==false){
      K+=(U+1)/2;
      U=0;
    }
    else if(G[X]==false){
      U++;
    }
  }
  K+=(U+1)/2;
  cout<<K<<endl;
}
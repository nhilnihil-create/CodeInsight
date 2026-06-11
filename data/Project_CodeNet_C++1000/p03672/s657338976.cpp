#include <bits/stdc++.h>
using namespace std;

bool A(string S){
  for(int i=0;i<S.size()/2;i++){
    if(S.at(i)!=S.at(i+S.size()/2)){
      return 1;
    }
  }
  return 0;
}

int main(){
  string N;cin>>N;
  N.pop_back();
  if(N.size()%2){
    N.pop_back();
  }
  while(A(N)){
    N.pop_back();
    N.pop_back();
  }
  cout<<N.size()<<endl;
}
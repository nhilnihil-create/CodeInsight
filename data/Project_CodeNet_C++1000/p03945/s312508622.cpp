#include<bits/stdc++.h>
using namespace std;

int main(){
  
  string S;
  int cnt=0;
  cin>>S;
  for(int i=0; i<S.size()-1; i++){
    if(S[i]!=S[i+1])cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}
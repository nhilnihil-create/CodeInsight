#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string S;
  cin>>S;
  
  vector<char> vec(S.size());
  for(int i=0;i<S.size();i++){
    vec[i]=S[i];
  }
  sort(vec.begin(),vec.end());
  
  
  bool check=true;
  
  for(int i=0;i<S.size();i++){
    if(vec[i]==vec[i+1]){
      check=false;
      break;
    }
  }
  
  
  if(check){
    cout<<"yes"<<endl;
  }
  else{
    cout<<"no"<<endl;
  }
}
#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string S,T;
  cin>>S>>T;
  
  if(S.size()>T.size()){
    cout<<"GREATER"<<endl;
    return 0;
  }
  else if(S.size()<T.size()){
    cout<<"LESS"<<endl;
    return 0;
  }
  else if(S.size()==T.size()){
    int x=0;
    for(int i=0;i<S.size();i++){
      if(S[i]>T[i]){
        cout<<"GREATER"<<endl;
        return 0;
      }
      else if(S[i]<T[i]){
        cout<<"LESS"<<endl;
        return 0;
      }
      else{
        x++;
      }
    }
    if(x==S.size()){
      cout<<"EQUAL"<<endl;
    }
  }
}
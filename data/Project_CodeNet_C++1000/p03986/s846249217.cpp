#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int temp=0;
  while(1){
    int OS=S.length();
    for(int i=temp;i<S.length()-1;i++){
      if(S.at(i)=='S' && S.at(i+1)=='T'){
        S=S.erase(i,2);
        if(i>10){
          temp=i-2;
        }
        else{
          temp=0;
        }
        break;
      }
    }
    if(S==""){
      cout<<0<<endl;
      return 0;
    }
    if(S.length()==OS){
      cout<<S.length()<<endl;
      return 0;
    }
  }
  return 0;
}

    
    
#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B;
  cin>>N>>A>>B;
  string S;
  cin>>S;
  int cnta=0,cntb=0,cntc=0,pas=0;
  
  for(int i=0;i<S.length();i++){
    /*if(S.at(i)=='a'){
      cnta++;
    }*/
    if(S.at(i)=='b'){
      cntb++;
    }      
    /*if(S.at(i)=='c'){
      cntc++;
    }  */  
    if(S.at(i)=='a'){
      if(pas<A+B){
        cout<<"Yes"<<endl;
        pas++;
      }
      else {
        cout<<"No"<<endl;
      }
    }
    if(S.at(i)=='b'){
      if(pas<A+B && cntb<=B){
        cout<<"Yes"<<endl;
        pas++;
      }
      else{
        cout<<"No"<<endl;
      }
    }    
    if(S.at(i)=='c'){
      cout<<"No"<<endl;
    }      
    
  }
  
}

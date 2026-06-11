#include <bits/stdc++.h>

using namespace std;

string A, B, C;

void system(string& s){
  if(s[0]=='a'){
    s.erase(0,1);
    if(A.empty()==1){
      cout<<"A"<<endl;
    } else {
      system(A);
    }
  } else if(s[0]=='b'){
    s.erase(0,1);
    if(B.empty()==1){
      cout<<"B"<<endl;
    } else {
      system(B);
    }
  } else if(s[0]=='c'){
    s.erase(0,1);
    if(C.empty()==1){
      cout<<"C"<<endl;
    } else{
      system(C); 
    }
  }
}


int main(){
  cin>>A>>B>>C;
  
  system(A);
       
}
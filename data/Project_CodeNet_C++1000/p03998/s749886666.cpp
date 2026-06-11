#include <bits/stdc++.h>
using namespace std;



int main() {
  string A,B,C;
  cin>>A>>B>>C;
  
  int ja=0;
  int jb=0;
  int jc=0;
  
  int kanri=1;
  while(true){
  if(kanri==1){
    if(ja==A.size()){
      cout<<'A'<<endl;
      return 0;
    }
    else{
      if(A.at(ja)=='a'){kanri=1;}
      else if(A.at(ja)=='b'){kanri=2;}
      else if(A.at(ja)=='c'){kanri=3;}
      ja++;
    }
  }
  else if(kanri==2){
    if(jb==B.size()){
      cout<<'B'<<endl;
      return 0;
    }
    else{
      if(B.at(jb)=='a'){kanri=1;}
      else if(B.at(jb)=='b'){kanri=2;}
      else if(B.at(jb)=='c'){kanri=3;}
      jb++;
    }
  }     
  else if(kanri==3){
    if(jc==C.size()){
      cout<<'C'<<endl;
      return 0;
    } 
    else{
      if(C.at(jc)=='a'){kanri=1;}
      else if(C.at(jc)=='b'){kanri=2;}
      else if(C.at(jc)=='c'){kanri=3;}
      jc++;
    }
  }
  }
}
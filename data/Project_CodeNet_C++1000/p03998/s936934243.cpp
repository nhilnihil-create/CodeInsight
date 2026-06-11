#include <bits/stdc++.h>
using namespace std;

int main(){
  string A,B,C;
  cin >> A >> B >> C;
  char next='a';
  int next_A=0,next_B=0,next_C=0;
  while(true){
    if(next=='a'){
      if(next_A==A.size()){
        cout << "A" << endl;
        break;
      }
      else{
        next=A.at(next_A);
        next_A++;
      }
    }
    if(next=='b'){
      if(next_B==B.size()){
        cout << "B" << endl;
        break;
      }
      else{
        next=B.at(next_B);
        next_B++;
      }
    }
    if(next=='c'){
      if(next_C==C.size()){
        cout << "C" << endl;
        break;
      }
      else{
        next=C.at(next_C);
        next_C++;
      }
    }
  }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
  string A,B,C;
  cin >> A >> B >> C;
  int countA=0,countB=0,countC=0;
  char next='a';
  while(true){
    if(next=='a'){
      if(countA==A.size()){
        cout << 'A' << endl;
        break;
      }
      next=A.at(countA);
      countA++;
    }
    if(next=='b'){
      if(countB==B.size()){
        cout << 'B' << endl;
        break;
      }
      next=B.at(countB);
      countB++;
    }
    if(next=='c'){
      if(countC==C.size()){
        cout << 'C' << endl;
        break;
      }
      next=C.at(countC);
      countC++;
    }
  }
}
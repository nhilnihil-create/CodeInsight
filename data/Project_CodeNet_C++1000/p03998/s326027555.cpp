#include <bits/stdc++.h>
using namespace std;
#define TO_STRING(VariableName) # VariableName
 
int counter(int Si, string S){
  if(S[Si] == 'a'){
    return 0;
  }else if(S[Si] == 'b'){
      return 1;
  }else{
      return 2;
  }
  
}

int main() {
 
  string A,B,C;
  cin >> A >> B >> C;
  
  int Ai=0,Bi=0,Ci=0;
  int Ac=A.size(),Bc=B.size(),Cc=C.size();
  
  int count = 0;
  
  while(true){

  	if(count == 0){ //A
      count = counter(Ai,A);
      Ai++;
      if(Ai == Ac + 1){
        cout << 'A' << endl;
        break;
      }
    }else  if(count == 1){ //B
      count = counter(Bi,B);
      Bi++;
      if(Bi == Bc + 1){
        cout << 'B' << endl;
        break;
      }
    }else{
      count = counter(Ci,C);
      Ci++;
      if(Ci == Cc + 1){
        cout << 'C' << endl;
        break;
      }
    }
  }

}
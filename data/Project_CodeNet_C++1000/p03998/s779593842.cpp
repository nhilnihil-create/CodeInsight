#include <bits/stdc++.h>
using namespace std;

int main() {
  string SA, SB, SC;
  cin >> SA >> SB >>SC;
  
  string Turn = "a";
  
  for ( int i = 0; i < 300 ; i++ ){
    if (Turn == "a"){
      if (SA.size() == 0){
        break;
      }
      Turn = SA.at(0);
      SA.erase(0, 1);
    }
    else if (Turn == "b"){
      if (SB.size() == 0){
        break;
      }
      Turn = SB.at(0);
      SB.erase(0, 1);
    }
    else if (Turn == "c"){
      if (SC.size() == 0){
        break;
      }
      Turn = SC.at(0);
      SC.erase(0, 1);
    }
  }
  
  if ( Turn == "a" ){
    cout << "A" ;
  }
  else if (Turn == "b" ){
    cout << "B" ;
  }
  else if ( Turn == "c" ){
    cout << "C" ;
  }
}

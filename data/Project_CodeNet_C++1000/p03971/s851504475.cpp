#include <bits/stdc++.h>
using namespace std;


int main() {
  int N, A, B;
  cin >> N >> A >> B;
  
  string S;
  cin >> S;
  
  int countAB = 0;
  int countB = 0;
  
  for (int i=0; i<N;i++){
    if(S.at(i) =='c'){
      cout << "No" << endl;
    }
    else if(S.at(i) =='a'){
      if(countAB<A+B){
        cout << "Yes" << endl;
        countAB = countAB + 1;
      }
      else {
        cout << "No" << endl;
      }
    }
    else if(S.at(i) =='b'){
      if(countB<B && countAB<A+B){
        cout << "Yes" << endl;
        countAB = countAB + 1;
        countB = countB + 1;
      }
      else{
        cout << "No" << endl;
      }
    }
  } 
      
  return 0;
}


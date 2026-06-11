#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N, A, B;
  int foreignRank = 0, pass = 0;
  string S;
  
  cin >> N >> A >> B;
  cin >> S;
  
  for(int i = 0; i < N; i++){
    if(S.at(i) == 'a'){
      if(pass < A + B){
        cout << "Yes" << endl;
        pass++;
      }
      else{
        cout << "No" << endl;
      }
    }
    else if(S.at(i) == 'b'){
      foreignRank++;
      if(pass < A + B && foreignRank <= B){
        cout << "Yes" << endl;
        pass++;
      }
      else{
        cout << "No" << endl;
      }
    }
    else{
      cout << "No" << endl;
    }
  }
}
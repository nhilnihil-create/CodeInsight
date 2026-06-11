#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, A, B;
  string S;
  cin >> N >> A >> B >> S;
  int pass = 0;
  int passB = 1;

  for(int i = 0 ; i < N ; i++){
    if(S[i] == 'a'){
      if(pass < A + B){
        pass ++;
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }else if(S[i] == 'b'){
      if(pass < A+B && passB <= B){
        passB++;
        pass++;
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }else if(S[i] == 'c'){
      cout << "No" << endl;
    }
  }
  return 0;
}

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A,B,P,PB;
  string S;
  cin >> N >> A >> B >> S;
  P = 0;
  PB = 0;
  for(int i = 0; i < N; i++){
    if (S[i] == 'a') {
      if (P < A+B){
      cout << "Yes" << endl;
      P += 1;
      }
      else{
        cout << "No" << endl;
      }
    }
    else if (S[i] == 'b') {
      if (P < A+B && PB < B){
      cout << "Yes" << endl;
      P += 1;
      PB += 1;
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
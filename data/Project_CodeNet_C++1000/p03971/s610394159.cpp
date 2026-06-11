#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  
  string S;
  cin >> S;
  
  vector<bool> ans(N, false);
  int Apass = 0, Bpass = 0;
  for (int i = 0; i < N; i++){
    if (S.at(i) == 'a'){
      if (Apass + Bpass < A + B){
        ans.at(i) = true;
        Apass++;
      }
    }
    else if (S.at(i) == 'b'){
      if (Apass + Bpass < A + B && Bpass < B){
        ans.at(i) = true;
        Bpass++;
      }
    }
  }
  
  for (int i = 0; i < N; i++){
    if (ans.at(i) == true){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
  }
}
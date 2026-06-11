#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int Anum, Znum;
  for(int i = 0; i < S.size(); i++){
    if(S.at(i) == 'A'){
      Anum = i;
      break;
    }
  }
  for(int i = S.size() - 1; i >= 0; i--){
    if(S.at(i) == 'Z'){
      Znum = i;
      break;
    }
  }
  cout << Znum - Anum + 1 << endl;
}
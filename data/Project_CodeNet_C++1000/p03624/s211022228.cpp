#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  vector<int> A(26);
  for(int i=0;i<S.size();i++){
    for(char C='a';C<='z';C++){
      if(S.at(i)==C){
        int B=C-'a';
        A.at(B)++;
        break;
      }
    }
  }
  bool a=false;
  for(int i=0;i<26;i++){
    if(A.at(i)==0){
      char D='a'+i;
      a=true;
      cout << D << endl;
      break;
    }
  }
  if(!a){
    cout << "None" << endl;
  }
}
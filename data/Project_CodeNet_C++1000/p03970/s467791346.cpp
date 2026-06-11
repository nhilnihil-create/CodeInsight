#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  string T="CODEFESTIVAL2016";
  int Ans=16;
  for(int i=0; i<16; i++){
    if(S.at(i)==T.at(i)){
      Ans--;
    }
  }
  cout << Ans << endl;
}
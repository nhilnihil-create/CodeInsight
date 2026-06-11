#include <bits/stdc++.h>
using namespace std;

int main() {
string S; cin>>S;
  string Z="CODEFESTIVAL2016";
  int A=0;
  for(int i=0; i<16; i++){
    if(S.at(i)==Z.at(i)) continue;
    else A++;
  }
  cout<<A<<endl;
}
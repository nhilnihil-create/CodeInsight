#include <bits/stdc++.h>
using namespace std;

int main() {
  string A,B,C;
  cin>>A>>B>>C;
  int Na=A.size();
  int Nb=B.size();
  int Nc=C.size();
  //Aの先頭A.at(0) Aの最後A.at(Na-1)
  if(A.at(Na-1)==B.at(0) && B.at(Nb-1)==C.at(0)){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}

#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int A=S.size();
  bool a=false;
  while(!a){
    A-=2;
    S=S.substr(0,A);
    string T=S.substr(0,A/2),U=S.substr(A/2,A/2);
    if(T==U){
      cout << A << endl;
      a=true;
    }
  }
}
    
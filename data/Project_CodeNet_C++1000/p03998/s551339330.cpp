#include <bits/stdc++.h>
using namespace std;
int main() {
  string A,B,C; cin>>A>>B>>C;
  char t='a';
  while(1){
    if(t=='a'){
      if(A.empty()){cout<<"A";return 0;}
      t=A[0];
      A.erase(A.begin());
    }
    else if(t=='b'){
      if(B.empty()){cout<<"B";return 0;}
      t=B[0];
      B.erase(B.begin());
    }
    else{
      if(C.empty()){cout<<"C";return 0;}
      t=C[0];
      C.erase(C.begin());
    }
  }
}
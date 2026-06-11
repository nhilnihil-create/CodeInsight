#include <bits/stdc++.h>
using namespace std;
#include <math.h>
int main() {
  string A,B,C;
  cin>>A>>B>>C;
  char x='a';
  while(true){
  if(x=='a'){
      if(A.empty()){cout<<'A'<<endl;return 0;}
   x=A[0];
   A.erase(0,1);
  }
  if(x=='b'){
      if(B.empty()){cout<<'B'<<endl;return 0;}
   x=B[0];
   B.erase(0,1);
  }
  if(x=='c'){
      if(C.empty()){cout<<'C'<<endl;return 0;}
   x=C[0];
   C.erase(0,1);
  }
  }
 return 0;}
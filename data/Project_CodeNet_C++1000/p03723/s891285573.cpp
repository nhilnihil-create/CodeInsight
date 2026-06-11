#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,ans=0;
  int a=0,b=0,c=0;
  cin >> A >> B >> C;
  if (A==B && B==C && A%2==1){
   cout << 0 << endl; 
  }
  else if (A==B && B==C){
   cout << -1 << endl; 
  }
  else {
  for (int i=0;;i++){
  if (A%2==1 || B%2==1 || C%2==1){
   break; 
  }
  else {
  a=A/2;
  b=B/2;
  c=C/2;
  A=b+c;
  B=c+a;
  C=a+b;
  ans++;
  }
  }
   cout << ans << endl;
  }
}
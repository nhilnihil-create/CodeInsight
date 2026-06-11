#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int A = a + b;
  int B = a + c;
  int C = b + c;
  if(A < B && A < C){
    cout << A <<endl;
  }
  else if( B < A && B < C){
    cout << B << endl;
  }
  else {
  cout << C <<endl;
  }
}

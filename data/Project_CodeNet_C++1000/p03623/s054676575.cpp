#include <bits/stdc++.h>
using namespace std;

int main(){
  int X,A,B,C,D;
  cin >> X >> A >> B;
  if(X>A){
    C=X-A;
  }
  else{
    C=A-X;
  }
  if(X>B){
    D=X-B;
  }
  else{
    D=B-X;
  }
  if(C<D){
    cout << "A" << endl;
  }
  else{
    cout << "B" << endl;
  }
}

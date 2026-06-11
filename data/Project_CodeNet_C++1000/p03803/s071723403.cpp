#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A,B;
  cin >> A >> B;
  if(A==1){
    A=14;
  }
  if(B==1){
    B=14;
  }
  if(A>B){
    cout << "Alice" << endl;
  }
  else if(A==B){
    cout << "Draw" << endl;
  }
  else if(A<B){
    cout << "Bob" << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B;
  cin >> A >> B;
  
  if(A==B){
    cout << "Draw" << endl;
  }
  else if(A>B){
    if(B==1){
      cout << "Bob" << endl;
    }
    else{
    cout << "Alice" << endl;
    }
  }
  else if(B>A){
    if(A==1){
      cout << "Alice" << endl;
    }
    else{
    cout << "Bob" << endl;
  } 
}
}
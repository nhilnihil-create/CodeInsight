#include<bits/stdc++.h>
using namespace std;

int main(){
  int X, A, B;
  cin >> X >> A >> B;

  int ans = A - B;
  X = -X;

  if (ans>=0){
    cout << "delicious" << endl;
  }
  else if (ans<0 && ans>=X){
    cout << "safe" << endl;
  }
  else {
    cout << "dangerous" << endl;
  }
}

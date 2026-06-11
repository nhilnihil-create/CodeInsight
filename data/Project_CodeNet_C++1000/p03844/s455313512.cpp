#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  string op;
  int kekka;
  cin >> A >> op >> B;
  
  if(op == "+"){
    kekka = A + B;
  }
  else kekka = A - B;
  
  cout << kekka << endl;
}

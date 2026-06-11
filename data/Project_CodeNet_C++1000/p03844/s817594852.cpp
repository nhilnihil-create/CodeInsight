#include <bits/stdc++.h>
using namespace std;

int main() {
  int A , B;
  cin >> A ;
  string op;
  cin >> op;
  cin >> B;
  if (op == "+"){
     cout << A + B << endl;
  }else if (op == "-"){
     cout << A - B << endl;
  } else if (op == "*"){
     cout << A * B << endl;
  } else if (op == "/" && B == 0){
     cout << "error" << endl;
  }else if (op == "/"){
    cout << A / B << endl;
  }else if (op == "="){
     cout << "error" << endl;
  }else if (op == "!"){
     cout << "error" << endl;
  }else if (op == "?"){
     cout << "error" << endl;
  }
}

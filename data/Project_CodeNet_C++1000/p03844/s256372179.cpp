#include <bits/stdc++.h>
using namespace std;

int main () {
  int A, B;
  string o;
  cin >> A >> o >> B;
  
  if (o=="+") {
    cout << A+B << endl;
  }
  if (o=="-") {
    cout << A-B << endl;
  }
}
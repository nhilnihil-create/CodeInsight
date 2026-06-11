#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, SR;
  cin >> S;
  
  int A = S.find("A");
  int Z = S.rfind("Z");
  
//  cout << A << endl;
//  cout << Z << endl;
  cout << Z - A + 1 ;
}
  
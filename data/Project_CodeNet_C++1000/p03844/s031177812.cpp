#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A;
  char ope;
  int B;
  
  cin >> A >> ope >> B;
  
  if (ope == '+')
    cout << A + B << endl;
  
  if (ope == '-')
    cout << A - B << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
  int A;
  cin >> A;
  if(A % 10 == 9) {
    cout << "Yes" << endl;
  }
  else if(A + 10 >= 100) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
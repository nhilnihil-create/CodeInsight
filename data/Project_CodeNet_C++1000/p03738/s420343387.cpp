#include <bits/stdc++.h>
using namespace std;
int main() {
  string A, B;
  cin >> A >> B;
  int a = A.size();
  int b = B.size();
  if(a > b) {
    cout << "GREATER" << endl;
  }
  else if(b > a) {
    cout << "LESS" << endl;
  }
  else {
    for(int i = 0; i < a; i++) {
      if(A[i] > B[i]) {
        cout << "GREATER" << endl;
        break;
      }
      else if(B[i] > A[i]) {
        cout << "LESS" << endl;
        break;
      }
      if(i == a - 1) {
        cout << "EQUAL" << endl;
      }
    }
  }
}
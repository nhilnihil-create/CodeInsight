#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string data;
  int N,A,B;
  int ok = 0;
  int B_cnt = 1;
  cin >> N >> A >> B;
  cin >> data;
  
  for (int i=0; i<N; i++) {
    if (data[i] == 'c') {
      cout << "No" << endl;
    }
    
    if (data[i] == 'a') {
      if (ok < A+B) {
        cout << "Yes" << endl;
        ok++;
      }
      else {
        cout << "No" << endl;
      }
    }
    if (data[i] == 'b') {
      if ((ok < A+B)&&(B_cnt <= B)) {
        cout << "Yes" << endl;
        B_cnt++;
        ok++;
      }
      else {
        cout << "No" << endl;
      }
    } 
  }
}
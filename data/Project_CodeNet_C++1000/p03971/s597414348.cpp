#include<bits/stdc++.h>
using namespace std;
int main() {
  
  int n, a, b, passed = 0, bc = 0; cin >> n >> a >> b;
  string s; cin >> s;
  
  for(int i = 0; i < n; i++) {
    if(s.at(i) == 'a') {
      if(passed < a + b) {
        cout << "Yes" << endl;
        passed++;
      }
      else {
        cout << "No" << endl;
      }
    }
    if(s.at(i) == 'b') {
      bc++;
      if(passed < a + b && bc <= b) {
        cout << "Yes" << endl;
        passed++;
      }
      else {
        cout << "No" << endl;
      }
    }
    if(s.at(i) == 'c') {
      cout << "No" << endl;
    }
  }
}
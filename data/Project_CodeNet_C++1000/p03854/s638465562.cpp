#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  for (int i = 0; i < 10; i++) {
  S += "1";
  }
  
  for (int i = 0; ;) {
    if (S.at(0) == '1') {
      cout << "YES" << endl;
      break;
    }
    else {
      if (S.at(0) == 'd') {
        if (S.at(7) != 'a' && S.substr(0, 7) == "dreamer") {
          S.erase(0, 7);
        }
        else if (S.substr(0, 5) == "dream") {
          S.erase(0, 5);
        }
        else {
          cout << "NO" << endl;
          break;
        }
      }
      
      if (S.at(0) == 'e') {
        if (S.substr(0, 6) == "eraser") {
          S.erase(0, 6);
        }
        else if (S.substr(0, 5) == "erase") {
          S.erase(0, 5);
        }
        else { 
          cout << "NO" << endl;  
          break;
        }
      }
      
      if (S.at(0) != 'd' && S.at(0) != 'e' && S.at(0) != '1') {
        cout << "NO" << endl;
        break;
      }
    }
  }
}
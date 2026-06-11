#include <bits/stdc++.h>
using namespace std;

int main() {
  string S; cin >> S;
  reverse(S.begin(),S.end());
  
  while (1) {
    int N = S.size();
    if (N >= 5) {
      string S5 = S.substr(0,5);
      if (S5 == "maerd" || S5 == "esare") {
      S.erase(0,5);
      } else if (N >= 6) {
        string S6 = S.substr(0,6);    
        if (S6 == "resare") {
          S.erase(0,6);
        } else if (N >= 7) {
          string S7 = S.substr(0,7);
          if (S7 == "remaerd") {
            S.erase(0,7);
          } else {
            break;
          }
        } else {
          break;
        }
      } else {
        break;
      }
    } else {
      break;
    }
  }
  if (S.size() == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}
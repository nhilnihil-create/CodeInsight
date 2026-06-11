#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string A, B, C;
  cin >> A >> B >> C;
  
  string turn;
  turn.push_back(A.at(0));
  
  while(true) {
    if(turn == "a") {
      if(A.empty()) {
        cout << "A" << endl;
        break;
      }
      
      turn = A.at(0);
      A.erase(A.begin());
    }
    if(turn == "b") {
      if(B.empty()) {
        cout << "B" << endl;
        break;
      }
      
      turn = B.at(0);
      B.erase(B.begin());
    }
    if(turn == "c") {
      if(C.empty()) {
        cout << "C" << endl;
        break;
      }
      
      turn = C.at(0);
      C.erase(C.begin());
    }
  }
}
 
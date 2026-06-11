#include <bits/stdc++.h>
using namespace std;
  
int main() {
  string SA,SB,SC; cin >> SA >> SB >> SC;
  char ans;
  char card = SA[0];
  SA.erase(0,1);
  while (true) {
    if (card == 'a') {
      int NA = SA.size();
      if (NA == 0) {
        ans = 'A';
        break;
      } else {
        card = SA[0]; SA.erase(0,1);
      }
    }
    if (card == 'b') {
      int NB = SB.size();
      if (NB == 0) {
        ans = 'B';
        break;
      } else {
        card = SB[0]; SB.erase(0,1);
      }
    }
    if (card == 'c') {
      int NC = SC.size();
      if (NC == 0) {
        ans = 'C';
        break;
      } else {      
        card = SC[0]; SC.erase(0,1);
      }
    }
  }
  cout << ans << endl;
}
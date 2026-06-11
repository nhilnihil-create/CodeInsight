#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int N;
  cin >> N;
  
  vector<int> button(N);
  int L1 = 0;
  int L2 = 0;
  int C = 0;
  
  for (int i = 0; i < N ; i++) {
     cin >> button.at(i);
  }
  
  while (L1 != 1) {
    
    if (button.at(L1) == -1) {
      cout << -1 << endl;
      break;
    }
    
    L1 = button.at(L1)-1;
    button.at(L2) = -1;
    L2 = L1;
    C++;
  }
  
  if (L1 == 1) {
    cout << C <<endl;
  }
}
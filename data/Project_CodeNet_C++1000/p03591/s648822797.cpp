#include <bits/stdc++.h>
using namespace std;

int main() {
 string  S;
   cin >> S;
  
    if ((S.size() < 4) ||((S.size() >= 4) && ((S.at(0) != 'Y') || (S.at(1) != 'A') || (S.at(2) != 'K') || (S.at(3) != 'I')))) {
      
     cout << "No" << endl;
  }
    else {
      cout << "Yes" << endl;
    }
  }
  

 

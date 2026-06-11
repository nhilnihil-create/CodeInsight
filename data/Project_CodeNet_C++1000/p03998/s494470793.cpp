#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string sA, sB, sC; cin >> sA >> sB >> sC;
  
  char tmp = 'a';
  
  while (true) {
    
    if (tmp == 'a') {
      
      if (sA == "") { cout << "A" << endl; return 0; }
      
      int sizeMemoA = sA.size(); tmp = sA.at(0);
      
      if (sizeMemoA == 1) sA = "";
      
      else sA = sA.substr(1, sizeMemoA - 1);
      
    }
    
    if (tmp == 'b') {
      
      if (sB == "") { cout << "B" << endl; return 0; }
      
      int sizeMemoB = sB.size(); tmp = sB.at(0);
      
      if (sizeMemoB == 1) sB = "";
      
      else sB = sB.substr(1, sizeMemoB - 1);
      
    }
    
    if (tmp == 'c') {
      
      if (sC == "") { cout << "C" << endl; return 0; }
      
      int sizeMemoC = sC.size(); tmp = sC.at(0);
      
      if (sizeMemoC == 1) sC = "";
      
      else sC = sC.substr(1, sizeMemoC - 1);
      
    }
    
  }
  
}
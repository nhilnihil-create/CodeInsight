#include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int r = 0,l = 0;
    	string A;
    	cin >> A;
      	sort(A.begin(), A.end());
      l = A.size();
      while(1){
        if (A.at(r) == A.at(r+1)){
          cout << "no" << endl;
        break;
        }
        r++;
        if(r + 1 == l){
          cout << "yes" <<endl;
          break;
        }
      }
      
      
    }
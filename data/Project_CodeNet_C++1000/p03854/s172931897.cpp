#include <bits/stdc++.h>
using namespace std;

int main () {
  string S;
  cin >> S;
  int N = S.size();
  
  for (int i = N-1; i >= 0; i--) {
    if (i <= 3){
      cout << "NO" << endl;
      return 0;
    }
    int count = 0;
    if (S.at(i-4) == 'd' && S.at(i-3) == 'r' && S.at(i-2) == 'e' && S.at(i-1) == 'a' && S.at(i) == 'm'){
      count++;
      i -= 4;
    }
    else if (S.at(i-4) == 'e' && S.at(i-3) == 'r' && S.at(i-2) == 'a' && S.at(i-1) == 's' && S.at(i) == 'e'){
      count++;
      i -= 4;
    }
    else if (i >= 5 && S.at(i-5) == 'e' && S.at(i-4) == 'r' && S.at(i-3) == 'a' && S.at(i-2) == 's' && S.at(i-1) == 'e' && S.at(i) == 'r'){
      count++;
      i -= 5;
    }
    else if (i >= 6 && S.at(i-6) == 'd' && S.at(i-5) == 'r' && S.at(i-4) == 'e' && S.at(i-3) == 'a' && S.at(i-2) == 'm' && S.at(i-1) == 'e' && S.at(i) == 'r'){
      count++;
      i -= 6;
    }
    if (count == 0){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl; 
}
  
    
   
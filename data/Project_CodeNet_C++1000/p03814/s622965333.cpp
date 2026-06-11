#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  int PA, PZ;
  for (int i =0; i < S.size() ; i++){
    if(S.at(i) == 'A'){
      PA = i;
      break;
    }
  }
  for (int i = S.size()-1 ; i > PA ; i--){
    if(S.at(i) == 'Z'){
      PZ = i;
      break;
    }
  }
    
  cout << PZ - PA + 1 << endl;
}

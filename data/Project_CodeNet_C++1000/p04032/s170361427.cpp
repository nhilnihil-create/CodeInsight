#include <bits/stdc++.h>
using namespace std;
     
int main() {
  string s;
  cin >> s;
  int C = s.size();
  
  int D = 0;
  
  for(int i = 0; i < C - 2; i++){
  if(s.at(i) == s.at(i + 1)){
    cout << i + 1 << " " << i + 2 << endl;
    D ++;
    break;
  }
    else if(s.at(i) == s.at(i + 2)){
      cout << i + 1 << " " << i + 3 << endl;
      D ++;
    break;
    }
  }
     if(s.at(C - 2) == s.at(C - 1) && D == 0){
    cout << C - 1 << " " << C << endl;
    D ++;
     }
  
  if(D == 0){
    cout << "-1 -1" << endl;
  }

}
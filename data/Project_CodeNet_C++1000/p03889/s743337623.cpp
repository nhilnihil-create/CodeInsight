#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

int main(){

  string S; cin >> S;
  string T;
  for (int i = 0; i < S.length(); i++){
    T += S[S.length() - 1 - i];
  }
  
  for (int i = 0; i < T.length(); i++){
    char A = T[i];
    if (A == 'b') A = 'd';
    else if (A == 'd') A = 'b';
    else if (A == 'p') A = 'q';
    else if (A == 'q') A = 'p';
    
    T[i] = A;
  }
  
  if (S == T) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
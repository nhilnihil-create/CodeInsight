#include <bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  long count = 0;
  string A =  "CODEFESTIVAL2016";
  for(int i = 0; i < 16; i++){
    if(A.at(i) != S.at(i)) count++;
  }
  cout << count << endl;
  return 0;
}
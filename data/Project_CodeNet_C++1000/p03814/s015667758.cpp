#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
 
  vector<char> s(S.size());
  for (int i = 0; i < S.size(); i++) {
    s.at(i) = S.at(i);
  }
  
  int a;
  for (int i = 0; i < S.size(); i++) {
    if (s.at(i) == 'A'){
      a = i;
      break;
    }
  }
  int z;
  for (int i = S.size()-1; i >= 0; i--) {
    if (s.at(i) == 'Z'){
      z = i;
      break;
    }
  }
  cout << z - a + 1 << endl;
}
      
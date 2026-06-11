#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
 
  vector<char> s(S.size());
  for (int i = 0; i < S.size(); i++) {
    s.at(i) = S.at(i);
  }
  
  int w = 0;
  for (int i = 0; i < S.size(); i++) {
    if (s.at(i) == 'W'){
      w++;
    }
  }
  int n = 0;
  for (int i = 0; i < S.size(); i++) {
    if (s.at(i) == 'N'){
      n++;
    }
  }
  int s1 = 0;
  for (int i = 0; i < S.size(); i++) {
    if (s.at(i) == 'S'){
      s1++;
    }
  }
  int e = 0;
  for (int i = S.size()-1; i >= 0; i--) {
    if (s.at(i) == 'E'){
      e++;
    }
  }
  if (w > 0 && e == 0){
    cout << "No" << endl;
  }
  else if (w == 0 && e > 0){
    cout << "No" << endl;
  }
  else if (s1 > 0 && n == 0){
    cout << "No" << endl;
  }
  else if (s1 == 0 && n > 0){
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}
      
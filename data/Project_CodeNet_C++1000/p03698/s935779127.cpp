#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  vector<char> S(s.size());
    for (int i = 0; i < s.size(); i++) {
      S.at(i) = s.at(i);
    }
  int count = 0;
  
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < s.size(); j++) {
      if (S.at(i) == S.at(j)){
        count++;
      }
    }
  }
  if (count == s.size()){
    cout << "yes" << endl;
  }
  else {
    cout << "no" << endl;
  }
}
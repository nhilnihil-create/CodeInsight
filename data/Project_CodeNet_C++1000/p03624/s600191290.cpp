#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  map<char,bool> list;
  for (int i=0; i<26; i++) {
    list['a'+i] = true;
  }
  char c;
  for (int i=0; i<s.size(); i++) {
    c = s.at(i);
    list[c] = false;
  }
  for (auto x:list) {
    if (x.second) {
      cout << x.first << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}
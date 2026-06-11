#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  set<char> list;
  for (int i=0; i<s.size(); i++) {
    list.insert(s.at(i));
  }
  if (list.size() == s.size()) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}
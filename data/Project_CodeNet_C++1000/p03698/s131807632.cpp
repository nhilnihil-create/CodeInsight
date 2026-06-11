#include<bits/stdc++.h>
using namespace std;
int main() {
  string s; cin >> s;
  int sizeofs = s.size();
  set<char> sat;
  for(int i = 0; i < sizeofs; i++) {
    sat.insert(s.at(i));
  }
  int sizeofsat = sat.size();
  if(sizeofsat == sizeofs) {
    cout << "yes" << endl;
  }
  else {
    cout << "no" << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  string O,E;
  cin >> O >> E;
 
  vector<char> o(O.size());
  for (int i = 0; i < O.size(); i++) {
    o.at(i) = O.at(i);
  }
  vector<char> e(E.size());
  for (int i = 0; i < E.size(); i++) {
    e.at(i) = E.at(i);
  }
  
  for (int i = 0; i < E.size(); i++) {
    cout << o.at(i) << e.at(i);
  }
  
  if (O.size() > E.size()){
    cout << o.at(O.size()-1) << endl;
  }
  else {
    cout << endl;
  }
}
  
  
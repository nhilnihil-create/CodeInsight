#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string a, b, c;
  cin >> a;
  int x = a.size();
  for(int i=0; i<x; i++) {
    a.pop_back();
    b = a.substr(0, a.size()/2);
    c = a.substr(a.size()/2);
      if(b==c) {
        cout << a.size() << endl;
        break;
      }
  }
  return 0;
}
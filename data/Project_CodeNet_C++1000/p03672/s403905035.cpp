#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  bool f = false;
  for (int j = a.size(); j >=0; j-=2) {
    if (j%2 == 1 && f == false) {
      f = true;
      a.pop_back();
    }
    string b = a.substr(0, a.size()/2);
    string c = a.substr(a.size()/2, a.size()-1);
    if (b == c && f) {
      cout << j << endl;
      break;
    }
    a.pop_back();
    a.pop_back();
    f = true;
  }
}
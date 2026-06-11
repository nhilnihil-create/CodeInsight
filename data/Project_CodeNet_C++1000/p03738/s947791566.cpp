#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  if(a == b) {
    cout << "EQUAL" << endl;
  }
  else if(a.size() > b.size()) {
    cout << "GREATER" << endl;
  }
  else if(a.size() < b.size()) {
    cout << "LESS" << endl;
  }
  else if(a.size() == b.size() && a > b) {
    cout << "GREATER" << endl;
  }
  else if(a.size() == b.size() && a < b) {
    cout << "LESS" << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string a;
  cin >> a;
  bool b = false;
  for(int i = 0; i < a.length(); i++) {
    if (a[i] == '9') {
      b = true;
    }
  }
  if (b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  cin >> a;
  int o = 0;
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a.size(); j++) {
      if (i != j) {
      if (a[i] == a[j]) {
        o++;
      }
    }
  }
  }
  if (o == 0) {
    cout << "yes" << endl;
  }
  else {
    cout << "no" << endl;
  }
}
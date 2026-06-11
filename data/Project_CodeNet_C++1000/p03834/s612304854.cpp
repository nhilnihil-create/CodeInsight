#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string a;
  cin >> a;
  for (int i = 0; i < 5; i++) {
    cout << a[i];
    if (i == 4) {
      cout << " ";
    }
  }
  for (int i = 6; i < 13; i++) {
    cout << a[i];
    if (i == 12) {
      cout << " ";
    }
  }
  for (int i = 14; i < 19; i++) {
    cout << a[i];
  }
       }
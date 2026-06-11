#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
  cout << "? 1000000000" << endl;
  char c;
  cin >> c;
  int L = 0;
  if (c == 'Y') {
    for (int i = 0; i <= 9; i++) {
      cout << "? 2";
      for (int j = 0; j < i; j++) cout << '0';
      cout << endl;
      cin >> c;
      if (c == 'Y') { L = i; break; }
    }
    cout << "! 1";
    for (int i = 0; i < L; i++) cout << '0';
    cout << endl;
  } else {
    L = 8;
    for (int i = 1; i < 9; i++) {
      cout << "? 1";
      for (int j = 0; j < i; j++) cout << '0';
      cout << endl;
      cin >> c;
      if (c == 'N') { L = i - 1; break; }
    }

    int lb = 1, ub = 10;
    for (int i = 0; i < L; i++) lb *= 10, ub *= 10;
    ub--;
    while (lb < ub) {
      int mid = (lb + ub) / 2;
      cout << "? " << mid << '0' << endl;
      cin >> c;
      if (c == 'Y') ub = mid;
      else lb = mid + 1;
    }
    cout << "! " << ub << endl;
  }
  return 0;
}

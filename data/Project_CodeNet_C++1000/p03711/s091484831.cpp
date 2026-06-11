#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  int group1 = 0, group2 = 0, group3 = 0;
  
  
  if (x == 2) {
    group3++;
  } else if (x == 4 || x == 6 || x == 9 || x == 11) {
    group2++;
  } else {
    group1++;
  }

  if (y == 2) {
    group3++;
  } else if (y == 4 || y == 6 || y == 9 || y == 11) {
    group2++;
  } else {
    group1++;
  }
  
  if (group1 == 2 || group2 == 2 || group3 == 2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  
}
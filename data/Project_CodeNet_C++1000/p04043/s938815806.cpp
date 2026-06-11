#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, n5, n7;
  n5 = n7 = 0;
  for (int i = 0; i < 3; i++) {
    cin >> n;
    if (n == 5)
      n5++;
    else if (n == 7)
      n7++;
  }
  if (n5 == 2 && n7 == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
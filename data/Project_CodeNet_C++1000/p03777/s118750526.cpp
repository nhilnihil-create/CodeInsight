#include <bits/stdc++.h>
using namespace std;

int main() {
  char a, t;
  cin >> a >> t;
  if (a == 'H' && t == 'H') {
    cout << 'H' << endl;
  }
  if (a == 'H' && t == 'D') {
    cout << 'D' << endl;
  }
  if (a == 'D' && t == 'H') {
    cout << 'D' << endl;
  }
  if (a == 'D' && t == 'D') {
    cout << 'H' << endl;
  }
}

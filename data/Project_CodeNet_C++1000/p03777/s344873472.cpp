#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  char a, b;
  cin >> a >> b;
  if ((a=='H' && b=='H') || (a=='D' && b=='D')) {
    cout << 'H' << endl;
  }
  else {
    cout << 'D' << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  char a, b; cin >> a >> b;
  if (a=='H' && b=='H') cout << "H";
  else if (a=='H' && b=='D') cout << "D";
  else if (a=='D' && b=='H') cout << "D";
  else cout << "H";
}
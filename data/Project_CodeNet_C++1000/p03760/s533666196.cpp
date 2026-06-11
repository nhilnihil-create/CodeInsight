#include <bits/stdc++.h>
using namespace std;
int main() {
  string O,E;
  cin >> O >> E;
  reverse(O.begin(),O.end());
  reverse(E.begin(),E.end());
  for (int i = 1; !O.empty() || !E.empty(); i++) {
    if (i%2) {
      cout << O.back();
      O.pop_back();
    } else {
      cout << E.back();
      E.pop_back();
    }
  }
}
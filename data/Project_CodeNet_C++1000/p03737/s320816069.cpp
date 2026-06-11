#include <bits/stdc++.h>
using namespace std;

int main() {
  int a = 'A'-'a';
  string s;
  for (int i=0; i<3; i++) {
    cin >> s;
    cout << char(s[0]+a);
  }
  cout << endl;
}

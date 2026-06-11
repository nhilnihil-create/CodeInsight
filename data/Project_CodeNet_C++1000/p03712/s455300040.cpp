#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
  cin >> a >> b;
  char c = '#';
  for (int i=0; i < b + 2; i++) {
    cout << c;
  }
  cout << endl;
  string s;
  for (int i=0; i < a; i++) {
    cin >> s;
    cout << c << s << c << endl;
  }
  for (int i=0; i < b + 2; i++) {
    cout << c;
  }
}
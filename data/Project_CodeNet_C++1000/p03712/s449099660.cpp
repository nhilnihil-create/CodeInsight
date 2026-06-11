#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  vector<string> c(a);
  vector<char> d(b + 2, '#');
  for(int i = 0; i < a; i++) {
    cin >> c.at(i);
  }
  for(int i = 0; i < b + 2; i++) {
    cout << d.at(i);
  }
  cout << endl;
  for(int i = 0; i < a; i++) {
    cout << '#' << c.at(i) << '#' << endl;
  }
  for(int i = 0; i < b + 2; i++) {
    cout << d.at(i);
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < (s.size() + 1) / 2; i++) cout << s.at(2 * i);
  cout << endl;
}

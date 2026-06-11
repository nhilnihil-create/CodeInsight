#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int count = 0; 
  for (int i = 0; i < (int)s.size() - 1; i++) {
    if (s.at(i) != s.at(i + 1)) count++;
  }
  cout << count << endl;
}
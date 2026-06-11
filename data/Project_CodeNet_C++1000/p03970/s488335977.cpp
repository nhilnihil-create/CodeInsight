#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int count = 0;
  string a = "CODEFESTIVAL2016";
  for (int i = 0; i < 16; i++) {
    if (s.at(i) != a.at(i)) {
      count++;
    }
  }
  cout << count << endl;
}


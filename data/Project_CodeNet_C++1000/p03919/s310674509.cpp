#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  string s;

  for(int i=0; i < a; i++) {
    for(int j=0; j < b; j++) {
      cin >> s;
      if (s == "snuke") cout << (char)(j+65) << i + 1 << endl;
    }
  }
}
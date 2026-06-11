#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool even = true;

  for(char c = 'a'; c <= 'z'; c++) {
    int count = 0;
    for(int i=0; i < s.size(); i++) {
      if(s[i] == c) {
        count++;
      }
    }
    if(count % 2 == 1) even = false;
  }
  cout << (even ? "Yes" : "No") << endl;
}
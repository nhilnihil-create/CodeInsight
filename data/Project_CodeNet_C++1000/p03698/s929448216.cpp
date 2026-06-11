#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int A[30] = {};
  string s;
  cin >> s;

  for(char ch = 'a'; ch <= 'z'; ch++) {
    for(int i = 0; i < s.size(); i++) {
      if(ch == s[i]) A[ch - 'a']++;
    }
  }
  for(int i = 0; i < 30; i++) {
    if(A[i] > 1) {
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
}
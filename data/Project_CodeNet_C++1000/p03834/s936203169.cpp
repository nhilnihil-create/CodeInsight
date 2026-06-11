#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  for(int i=0; i<19; i++) {
    if(s[i] == ',') s[i] = ' ';
  }
  cout << s << endl;
}
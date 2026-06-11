#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, sb, se, ans;
  int size=0;
  
  cin >> s;
  sb = s.at(0);
  se = s.at(s.size() -1);
  size = s.size() - 2;
  
  cout << sb << size << se << endl;
  return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  string s;
  cin >> s;
  int a[26] = {};

  for(int i = 0; i < s.size(); i++) {
    a[s[i]-char(0x61)] += 1;
  }

  bool flag = true;
  for(int i = 0; i < s.size(); i++) {
    if(a[i] > 1) flag = false;
  }
  if(flag) cout << "yes" << endl;
  else cout << "no" << endl;
  return 0;
}
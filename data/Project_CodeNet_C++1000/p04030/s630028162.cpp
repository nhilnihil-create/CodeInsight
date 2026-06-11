#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main() {
  string s;
  string out;
  getline(cin,s);
  for (int i=0; i < (int)s.length(); i++) {
    if (s[i] == 'B' && out.length() > 0) out.erase(out.length()-1);
    else if (s[i] != 'B') out.push_back(s[i]);
  }
  cout << out << endl;
  return 0;
}

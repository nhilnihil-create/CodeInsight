#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <fstream>
 
using namespace std;
 
ifstream fin("../data.txt");
 
string s;
 
int main() {
 
  getline(cin, s);
  int a = 0, b = s.size() - 1;
  while(s[a] != 'A' || s[b] != 'Z') {
    if (s[a] != 'A') a++;
    if (s[b] != 'Z') b--;
  }
 
  cout << b - a + 1;
 
  return 0;
}
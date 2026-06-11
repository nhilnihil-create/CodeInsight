#include <iostream>
#include <string>
#include <set>
#include <regex>
using namespace std;

int main () {
  string s;
  cin >> s;

  s = regex_replace(s, regex(","), " ");
  
  cout << s << endl;
}
#include <iostream>
#include <string>
#include <set>
#include <regex>
#include <locale>
using namespace std;

int main () {
  string a, b, c;
  cin >> a >> b >> c;
  
  locale loc;
  cout << toupper(a[0], loc) << toupper(b[0], loc) << toupper(c[0], loc) << endl;
}
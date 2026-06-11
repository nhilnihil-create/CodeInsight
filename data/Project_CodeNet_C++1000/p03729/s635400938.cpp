#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <regex>
#include <locale>
using namespace std;

int main () {
  string a, b, c;
  cin >> a >> b >> c;
  
  cout << ((reverse(a.begin(),a.end()), a[0] == b[0]) && (reverse(b.begin(),b.end()), b[0] == c[0]) ? "YES" : "NO") << endl;
}
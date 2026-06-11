#include <iostream>
using namespace std;

int main() {
  string s, str="CODEFESTIVAL2016";
  int n=0;
  cin >> s;

  for (int i=0; i<s.size(); i++) {
    if (s[i]!=str[i]) n++;
  }
  cout << n;
}
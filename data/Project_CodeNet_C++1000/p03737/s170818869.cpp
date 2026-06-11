#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b,c;
  string kekka;
  cin >> a >> b >> c;
  
  kekka = toupper(a.at(0));
  kekka += toupper(b.at(0));
  kekka += toupper(c.at(0));
  cout << kekka;
}

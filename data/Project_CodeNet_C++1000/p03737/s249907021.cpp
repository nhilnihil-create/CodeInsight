#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main() {
  
  string a, b, c;
  cin >> a >> b >> c;
  string abc = "";
  abc = abc + a.at(0) + b.at(0) + c.at(0);
  transform(abc.begin(), abc.end(), abc.begin(), ::toupper);
  cout << abc << endl;
}
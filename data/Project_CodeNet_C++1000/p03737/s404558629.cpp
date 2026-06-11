#include <bits/stdc++.h>
using namespace std;
int main() {
  string a,b,c;
  cin >> a >> b >> c;
  string x = a.substr(0,1) + b.substr(0,1) + c.substr(0,1);
  transform(x.begin(),x.end(),x.begin(),::toupper);
  cout << x << endl;
}
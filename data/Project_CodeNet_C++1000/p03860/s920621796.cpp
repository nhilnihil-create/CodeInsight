#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string a, s;
  cin >> a >> s >> a;
  
  string x = "ABC";
  x.at(1) = s.at(0);

  cout << x << endl;
}
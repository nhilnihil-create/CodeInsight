#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int f, e;
  f = s.find("A");
  e = s.rfind("Z");
  cout << e-f+1 << endl;
  return 0;
}

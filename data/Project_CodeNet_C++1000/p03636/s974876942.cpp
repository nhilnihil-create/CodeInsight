#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s;
  int x = s.size();
  int a = x - 2;
  
  t = s.at(0);
  cout << t;
  cout << a;
  t = s.at(x - 1);
  cout << t << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int a, z;
  a = s.find('A');
  z = s.rfind('Z');
  cout << z - a + 1 << endl;
}

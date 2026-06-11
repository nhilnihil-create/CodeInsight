#include <bits/stdc++.h>
using namespace std;
int main(void)
{
  int i,len;
  string a;
  char b,c;
  cin >> a;
  len = a.length();
  b = a[0];
  c = a[len-1]; 
  cout << b << len-2 << c;
  return 0;
}
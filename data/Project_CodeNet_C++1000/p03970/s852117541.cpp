#include <bits/stdc++.h>
using namespace std;

int main()
{
string s;
  cin >> s;
  string m = "CODEFESTIVAL2016";
  
  int sum = 0;
  for (int i= 0;i < m.length(); i++)
    if (s[i] != m[i])
      sum++;
  cout << sum << endl;
}
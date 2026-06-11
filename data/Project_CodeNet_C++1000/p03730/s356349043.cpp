#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int a,b,c;
  string ans = "YES";
  cin >> a >> b >> c;

  for(int i = 1; i < 1000; i++)
    if(a*i % b == c) goto Exit;
  
  ans = "NO";
  Exit: ;
  cout << ans << endl;
}
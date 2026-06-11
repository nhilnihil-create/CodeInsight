#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string s,t;
  cin >> s;

  for(int i = 0; i < s.size(); i++) {
    if(i % 2 == 0) 
        t += s[i];
    else continue;
  }
  cout << t << endl;
}
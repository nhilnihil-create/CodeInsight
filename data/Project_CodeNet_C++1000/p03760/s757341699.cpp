#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string s,t;
  cin >> s >> t;
  
  for(int i = 0; i < (s.size()+t.size()); i++) {
    if(i % 2 == 0) cout << s[i/2];
    else cout << t[(i-1)/2];
  }
  cout << endl;
}
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string w;
  cin >> w;
  
  int a[1000];
  for(int i = 0; i < 1000; i++)
    a[i] = 0;

  for(char ch = 'a'; ch <= 'z'; ch++) {
    for(int i = 0; i < w.size(); i++)
      if(w[i] == ch) a[ch-'0']++;
  }
  bool flag = 0;
  for(int i = 0; i < 1000; i++) {
    if(a[i] % 2 == 0) flag = 1;
    else {
      cout << "No" << endl;
      return 0;
    }
  }
  if(flag) cout << "Yes" << endl;
}
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
  string s;
  cin >> s;
  int r = s.length();
  int r2 =  s.length() -2 ;
  cout << s.at(0) << r2 << s.at(r-1) << endl;
}

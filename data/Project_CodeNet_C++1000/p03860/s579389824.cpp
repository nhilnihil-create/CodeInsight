#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char initial;
  string s;
  getline(cin, s);
  
  int i = 0;
 
  for(; i < s.size(); i++){
    if(s.at(i) == ' ')
       break;
  }
  
  cout << 'A' << s.at(i+1) << 'C' << endl;
  
  // ここにプログラムを追記
}
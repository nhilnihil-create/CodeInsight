#include<bits/stdc++.h>
using namespace std;

int main() { 
  string s;
  cin >> s;
  int a = 0;
  int z = 0;
  for(int i = 0; i < s.length(); i++) {
    if(s.at(i) == 'A') {
      a = i;
      break;
    }
  }
  for(int i = 0; i < s.length(); i++) {
    if(s.at(i) == 'Z') {
      z = i;
    }
  }
  cout << z - a + 1 << endl;
}
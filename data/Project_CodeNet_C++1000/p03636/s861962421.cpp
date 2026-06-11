#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int c=s.size()-2;
  string str = to_string(c);
  
  string t=s.at(0)+str+s.at(s.size()-1);
  cout << t << endl;
  
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  int size;
  char f,e;
  cin >> str;
  
  f = str.at(0);
  e = str.at(str.size()-1);
  size = str.size() - 2;
  
  cout << f + to_string(size) + e;  
}

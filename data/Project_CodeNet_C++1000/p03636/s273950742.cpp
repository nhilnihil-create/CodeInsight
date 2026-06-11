#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int s_size;
  s_size = str.size();
  char first = str.at(0);
  char last = str.at(s_size - 1);
  
  cout << first << s_size - 2 << last << endl;
}
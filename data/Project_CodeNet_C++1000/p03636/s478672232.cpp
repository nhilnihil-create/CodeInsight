#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string s; cin >> s;
  
  int tmp = s.size() - 2;
  
  cout << s.front() + to_string(tmp) + s.back() << endl;
  
}
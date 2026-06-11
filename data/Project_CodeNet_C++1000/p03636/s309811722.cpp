#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int num = s.size() - 2;
  cout << s.substr(0, 1) + to_string(num) + s.substr(s.size() - 1, 1) << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  set<int> values;
  int n = s.size();
  
  for (int i = 0; i < n; i++) values.insert(stoi(to_string(s.at(i))));

  int code = 97;
  for (auto x : values) if (x == code) code++;
  
  if (code == 123) cout << "None" << endl;
  else {
    char c = (char)code;
    printf("%c", c);
  }
}
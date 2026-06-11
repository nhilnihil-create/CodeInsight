#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  vector<bool> dict(26, false);
  
  sort(S.begin(), S.end());
  
  for (int i = 0; i < S.size(); ++i) {
    int idx = S.at(i) - 'a';
    dict.at(idx) = true;  
  }
  
  bool found = false;
  for (int i = 0; i < 26; ++i) {
    if (dict.at(i) == false) {
      char ch = 'a' + i;
      cout << ch << endl;
      found = true;
      break;
    }
  }
  if (!found) cout << "None" << endl;
  
}
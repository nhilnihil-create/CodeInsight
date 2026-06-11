#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  sort(s.begin(),s.end());
  vector<char>t;
  t.push_back(s[0]);
  for (int i = 0; i < s.size()-1; i++) {
    if (s[i]!=s[i+1]) {
      t.push_back(s[i+1]);
    }
  }

  for (char i = 'a'; i < 'z'+1; i++) {
    if (i==t[i-'a']) {
      continue;
    }
    else {
      cout << i << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}



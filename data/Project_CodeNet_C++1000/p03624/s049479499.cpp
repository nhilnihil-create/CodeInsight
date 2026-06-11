#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  set<char> st;
  for (int i = 0; i < s.size(); i++) {
    st.insert(s.at(i));
  }
  for (int i = 0; i < 26; i++) {
    if (!st.count(i + 'a')) {
      char c = i + 'a';
      cout << c << endl;
      return 0;
    }
  }
  cout << "None" << endl;
  return 0;
}

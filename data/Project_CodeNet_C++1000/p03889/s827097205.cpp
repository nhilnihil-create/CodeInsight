#include <bits/stdc++.h>
using namespace std;

string b = "bdpq";
string c = "dbqp";

int main() {
  string s, t;
  cin >> s;
  for (int i = 0; i < s.size(); i++)
    for (int j = 0; j < 4; j++)
      if (s[i] == b[j])
        t.push_back(c[j]);
  reverse(t.begin(), t.end());
  if (s == t)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  smatch match;

  if (regex_search(s, match, regex("A[A-Z]+Z"))) {
    cout << match[0].length() << endl;
  }
}
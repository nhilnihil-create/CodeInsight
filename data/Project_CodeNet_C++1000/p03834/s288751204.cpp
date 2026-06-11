#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  string s;
  cin >> s;
  for (int i=0; i<19; i++) {
    if (i==5 || i==13) {
      cout << " ";
      continue;
    }
    cout << s[i];
  }
  cout << endl;
}
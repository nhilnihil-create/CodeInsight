#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  set<char> SSS;
  for (char c:S) {
    SSS.insert(c);
  }
  if (S.size()==SSS.size()) {
    cout << "yes" << endl;
  }
  else {
    cout << "no" << endl;
  }
}

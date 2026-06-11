#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  if (S.size() < 4) cout << "No" << endl;
  else if (S.substr(0, 4) != "YAKI") cout << "No" << endl;
  else cout << "Yes" << endl;
}
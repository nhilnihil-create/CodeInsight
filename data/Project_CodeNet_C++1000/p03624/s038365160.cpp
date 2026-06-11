#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  string a = "abcdefghijklmnopqrstuvwxyz";
  map<char, bool> m;
  for (int i = 0; i < S.size(); i++) {
  	char c = S[i];
    m[c] = true;
  }
  bool flag = false;
  for (int i = 0; i < a.size(); i++) {
  	char key = a[i];
    if (!m[key]) {
      flag = true;
      cout << key << endl;
      break;
    }
  }
  if (!flag) {
  	cout << "None" << endl;
  }
}
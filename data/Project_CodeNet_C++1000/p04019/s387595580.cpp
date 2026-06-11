#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  bool N = false;
  bool S = false;
  bool W = false;
  bool E = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'N') {
      N = true;
    }
    if (s[i] == 'S') {
      S = true;
    }
    if (s[i] == 'W') {
      W = true;
    }
    if (s[i] == 'E') {
      E = true;
    }
  }
  if (N == S && W == E) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}

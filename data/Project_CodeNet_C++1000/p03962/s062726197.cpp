#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  vector<int> abc(3);
  rep(i, 3) cin >> abc.at(i);
  if (abc.at(0) == abc.at(1)) {
    if (abc.at(0) == abc.at(2)) cout << 1 << endl;
    else cout << 2 << endl;
  }
  else {
    if (abc.at(0) == abc.at(2) || abc.at(1) == abc.at(2)) cout << 2 << endl;
    else cout << 3 << endl;
  }
}
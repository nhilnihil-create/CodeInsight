#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s;
  for(int i = 0;i < s.size();i = i + 2) {
    t = t + s.at(i);
  }
  cout << t << endl;
}

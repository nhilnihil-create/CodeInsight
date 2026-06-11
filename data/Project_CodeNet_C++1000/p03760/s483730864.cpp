#include <bits/stdc++.h>
using namespace std;
int main() {
  string s,t;
  cin >> s >> t;
  int size = min(s.size(),t.size());
  for (int i=0; i<size; i++) {
    cout << s.at(i) << t.at(i);
  }
  if (s.size() > t.size()) {
    cout << s.at(s.size()-1) << endl;
  } else if (s.size() < t.size()) {
    cout << t.at(t.size()-1) << endl;
  } else {
    cout << endl;
  }
}
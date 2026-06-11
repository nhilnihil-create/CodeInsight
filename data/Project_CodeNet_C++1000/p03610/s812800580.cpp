#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s;
  
  for (int i = 0; i < s.size(); i++){
    if (i % 2 != 1)
      t += s.at(i); }
  
  cout << t << endl;
}

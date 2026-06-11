#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int g = 0, p = 0, pt = 0;
  for(auto c : s) {
    if(g == p) {
      pt -= ('g' != c);
      g++;
    } else {
      p++;
      if(c == 'g')
        pt++;
    }
  }
  cout << pt << '\n';
}
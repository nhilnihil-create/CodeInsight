#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, x = 0; cin >> n;
  string s; cin >> s;
  vector<int> xat(n +1);
  xat.at(n) = 0;
  for(int i = 0; i < n; i++) {
    if(s.at(i) == 'I') {
      x++;
    }
    else {
      x--;
    }
    xat.at(i) = x;
  }
  sort(xat.begin(), xat.end());
  cout << xat.at(n) << endl;
}
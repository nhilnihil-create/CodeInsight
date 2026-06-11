#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  
  vector<vector<char>> map(h,vector<char>(w));
  
  for (int i = 0; i < w + 2; i++) {
    cout << '#';
    if (i == w + 1) cout << endl;
  }
  
  for (int i = 0; i < h; i++) {
    cout << '#';
    for (int j = 0; j < w; j++) {
      char x;
      cin >> x;
      cout << x;
    }
    cout << '#' << endl;
  }
  
  for (int i = 0; i < w + 2; i++) {
  cout << '#';
  if (i == w + 1) cout << endl;
  }
}
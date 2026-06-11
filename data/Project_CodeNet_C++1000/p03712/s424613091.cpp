#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  string t;
  cin >> h >> w;
  
  for (int i = 0; i < h+2; i++) {
    if (i==0||i==h+1) {
      for (int j = 0; j < w+2; j++) {
        cout << "#";
      }
      cout << endl;
    }
    else {
      cin >> t;
      cout << "#" << t << "#"<< endl;
    }
  }
}

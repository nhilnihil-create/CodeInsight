#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  string floorCeil;
  for (int i=0; i<W+2; i++) {
    floorCeil.push_back('#');
  }
  
  for (int i=0; i<H; i++) {
    if (i == 0) {
      cout << floorCeil << endl;
    }
    string s;
    cin >> s;
    cout << "#" << s << "#" << endl;
  }
  cout << floorCeil << endl;
}
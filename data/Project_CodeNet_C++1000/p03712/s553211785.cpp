#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<char> picture(H*W);
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> picture.at(i*W+j);
    }
  }
  for (int j=0; j<W+2; j++) {
    cout << "#";
  }
  cout << endl;
  for (int i=0; i<H; i++) {
    cout << "#";
    for (int j=0; j<W; j++) {
      cout << picture.at(i*W+j);
    }
    cout << "#" << endl;
  }
  for (int j=0; j<W+2; j++) {
    cout << "#";
  }
  cout << endl;
}
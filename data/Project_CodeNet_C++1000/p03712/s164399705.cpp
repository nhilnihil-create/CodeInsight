#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  W += 2;
  vector<string> A(H);
  for (int i=0; i < W; i++) {
    cout << "#";
  }
  cout << endl;
  
  for (int i=0; i < H; i++) {
    cin >> A.at(i);
    cout << "#" << A.at(i) << "#" << endl;
  }
  for (int i=0; i < W; i++) {
    cout << "#";
  }
  cout << endl;
}
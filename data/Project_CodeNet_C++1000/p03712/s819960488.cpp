#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  char A;
  cin >> H >> W;
  
  vector<string> top(W + 2, "#");
  for (int i = 0; i < W + 2; i++) cout << top.at(i);
  
  cout << endl;
  
  vector<string> mid(W + 2, "#");
  for (int j = 0; j < H; j++) {
    for (int i = 0; i < W + 2; i++) {  
      if (i > 0 && i < W + 1) {
        cin >> A;
        mid.at(i) = A;
      }
      cout << mid.at(i);
    }
    cout << endl;
  }
  
  vector<string> btm(W + 2, "#");
  for (int i = 0; i < W + 2; i++) cout << btm.at(i);
  
  cout << endl;
}
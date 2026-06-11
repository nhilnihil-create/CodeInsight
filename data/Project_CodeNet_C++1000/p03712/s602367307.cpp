#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  
  vector<string> image(H);
  
  for (int w = 0; w < W + 2; w++) {
    cout << '#';
  }
  cout << endl;
  
  for (int h = 0; h < H; h++) {
    for (int i = 0; i < 3; i++) {
      if (i == 0) {
        cout << '#';
      } else if (i == 1) {
        string pixels;
        cin >> pixels;
        cout << pixels;
      } else {
        cout << '#' << endl;
      }
    }
  }
  for (int w = 0; w < W + 2; w++) {
    cout << '#';
  }
  cout << endl;
}

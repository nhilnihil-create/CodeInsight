#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<string> pixel(H);
 
  cout << '#';
  for (int i = 0; i < W; i++) {
    cout << '#';
  }
  cout << '#' << endl;
  
  for (int i = 0; i < H; i++) {
    cout << '#';
    cin >> pixel.at(i);
    cout << pixel.at(i);
    cout << '#' << endl;
  }
  
  cout << '#';
  for (int i = 0; i < W; i++) {
    cout << '#';
  }
  cout << '#' << endl;
}

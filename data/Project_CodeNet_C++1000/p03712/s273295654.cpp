#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  string a;
  for(int i = -2; i < W; i++) {
    a += "#";
  }

  cout << a << endl;
  for(int i = 0; i < H; i++) {
    string line;
    cin >> line;
    cout << '#' << line << '#' << endl;
  }
  
  cout << a << endl;
}
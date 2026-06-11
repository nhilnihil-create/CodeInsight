#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  string str;
  for (int i = 0; i < W + 2; i++)
    cout << "#";
  cout << endl;
  for (int i = 0; i < H; i++){
    cin >> str;
    cout << "#";
    for (int j = 0; j < W; j++)
      cout << str.at(j);
    cout << "#" << endl;
  }
  for (int i = 0; i < W + 2; i++)
    cout << "#";
  cout << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < W + 1; i++) {cout << "#";}
  cout << "#" << endl;
  for (int i = 0; i < H; i++) {
    string a;
    cin >> a;
    cout << "#" << a << "#" << endl;
  }
  for (int i = 0; i < W + 1; i++) {cout << "#";}
  cout << "#" << endl;
}
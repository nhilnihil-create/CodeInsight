#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  string base = "##";
  for (int i = 0; i < W; i++){
    base += '#';
  }
  cout << base << endl;
  string s;
  for (int i = 0; i < H; i++){
    cin >> s;
    cout << '#' + s + '#' << endl;
  }
  cout << base << endl;
}
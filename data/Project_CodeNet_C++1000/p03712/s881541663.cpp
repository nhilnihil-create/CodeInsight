#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<string> image(H+2);
  
  string sharp;
  
  for (int i = 0; i < W+2; i++) sharp += "#";
  
  image.at(0) = sharp;
  image.at(H+1) = sharp;
  
  for (int i = 0; i < H; i++) {
    string a;
    cin >> a;
    a = "#" + a + "#";
    image.at(i+1) = a;
  }
  
  for (int i = 0; i < (H+2); i++) {
    cout << image.at(i) << endl;;
  }
}
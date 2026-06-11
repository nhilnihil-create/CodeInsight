#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  string a;
  vector<char> s(W+2, '#');
  
  for (int i = 0; i < W+2; i++) {
    cout << s.at(i);
  }
  
  cout << endl;
  
  for (int i = 0; i < H; i++) {
    cin >> a;
    cout << '#' << a << '#' << endl;
  }
      
  for (int i = 0; i < W+2; i++) {
    cout << s.at(i);
  }
  
  cout << endl;
}
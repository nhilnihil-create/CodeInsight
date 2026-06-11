#include <iostream>
#include <vector>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> v(h,vector<char>(w));
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> v[i][j];
    }
  }
  for(int i = 0; i < w+2; i++) cout << "#";
  cout << "\n";
  for(int i = 0; i < h; i++) {
    cout << "#";
    for(int j = 0; j < w; j++) {
      cout << v[i][j];
    }
    cout << "#\n";
  }
  for(int i = 0; i < w+2; i++) cout << "#";
  cout << "\n";
}
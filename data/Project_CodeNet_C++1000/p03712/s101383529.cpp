#include <iostream>
#include <string>

using namespace std;

int main() {
  int H, W;
  string line;
  cin >> H >> W;
  cout << string(W+2, '#') << endl;
  for (int h = 0; h < H; ++h) {
    cin >> line;
    cout << '#' << line << '#' << endl;
  }
  cout << string(W+2, '#') << endl;
  
  return 0;
}

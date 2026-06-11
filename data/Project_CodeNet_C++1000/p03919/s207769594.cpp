#include <iostream>

using namespace std;

int main()
{
  int H, W; cin >> H >> W;

  int row = 0, col = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      string s; cin >> s;
      if (s == "snuke") {
        col = i + 1;
        row = j;
      }
    }
  }
  cout << (char)(row + 'A') << col << endl;
  return 0;
}
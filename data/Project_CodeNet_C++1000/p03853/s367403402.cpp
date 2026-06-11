# include <iostream>
# include <cmath>
using namespace std;

int main() {
  int h, w; cin >> h >> w;
  char pixels[h + 1][w + 1];
  
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      cin >> pixels[i][j];
    }
  }
  
  for (int i = 1; i <= 2 * h; ++i) {
    for (int j = 1; j <= w; ++j) {
      int height = ceil(i / 2.0);
      cout << pixels[height][j];
    }
    cout << endl;
  }
  
  return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;

int main() {
  int h, w;
  cin >> h >> w;
  char c[110][110];

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> c[i][j];
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << c[i][j];
    }
    cout << endl;
    for (int j = 0; j < w; j++) {
      cout << c[i][j];
    }
    cout << endl;
  }
  return 0;
}
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

  char a[110][110];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < w + 2; i++) {
    cout << "#";
  }
  cout << endl;

  for (int i = 0; i < h; i++) {
    cout << "#";
    for (int j = 0; j < w; j++) {
      cout << a[i][j];
    }
    cout << "#" << endl;
  }

  for (int i = 0; i < w + 2; i++) {
    cout << "#";
  }
  cout << endl;
  return 0;
}
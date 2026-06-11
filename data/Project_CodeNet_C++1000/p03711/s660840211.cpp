#include <iostream>
using namespace std;
int main()
{
  int gp[3][7] = {
    {1,3,5,7,8,10,12},
    {4,6,9,11},
    {2},
  };
  int x, y;
  cin >> x >> y;
  int xg= 0, yg = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < sizeof(gp[i])/sizeof(int); j++) {
      if (gp[i][j] == x) {
        xg = i;
      }
      if (gp[i][j] == y) {
        yg = i;
      }
    }
  }
  if (xg == yg) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}

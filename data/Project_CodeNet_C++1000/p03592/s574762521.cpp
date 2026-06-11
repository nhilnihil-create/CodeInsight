#include <bits/stdc++.h>
using namespace std;

int main()
{
  bool yes = false;
  int ROW, COL, K;
  cin >> ROW >> COL >> K;
  if (K % ROW == 0 || K % COL == 0)
  {
    yes = true;
  }
  else
  {
    for (int row = 1; row <= ROW; row++)
    {
      for (int col = 1; col <= COL; col++)
      {
        int k = COL * row + (ROW - 2 * row) * col;
        if (k == K)
        {
          yes = true;
          break;
        }
      }
    }
  }
  cout << (yes ? "Yes" : "No") << endl;
}

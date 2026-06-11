#include <bits/stdc++.h>
using namespace std;

int main()
{
  int sx, sy, tx, ty;
  int a, b;
  a = b = 0;
  cin >> sx >> sy >> tx >> ty;
  for (int i = sy; i < ty; i++)
  {
    cout << "U";
    a++;
  }
  for (int i = sx; i < tx; i++)
  {
    cout << "R";
    b++;
  }
  while (a--)
  {
    cout << "D";
  }
  while (b--)
  {
    cout << "L";
  }
  cout << "L";
  for (int i = sy; i <= ty; i++)
  {
    cout << "U";
    a++;
  }
  for (int i = sx; i <= tx; i++)
  {
    cout << "R";
    b++;
  }
  cout << "D";
  cout << "R";
  a++;
  b++;
  while (a--)
  {
    cout << "D";
  }
  while (b--)
  {
    cout << "L";
  }
  cout << "U" << endl;
}

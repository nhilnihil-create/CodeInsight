#include <iostream>
#include <string>
using namespace std;

int main()
{
  int g1[7] = {1, 3 , 5, 7, 8, 10, 12};
  int g2[4] = {4, 6, 9, 11};
  int g3[1] = {2};
  
  int x, y;
  char gx, gy;
  
  cin >> x >> y;
  
  for(int i = 0; i < sizeof(g1); i++)
  {
    if(x == g1[i])
    {
      gx = 'A';
    }
    if(y == g1[i])
    {
      gy = 'A';
    }
  }
  for(int i = 0; i < sizeof(g2); i++)
  {
    if(x == g2[i])
    {
      gx = 'B';
    }
    if(y == g2[i])
    {
      gy = 'B';
    }
  }
    for(int i = 0; i < sizeof(g3); i++)
  {
    if(x == g3[i])
    {
      gx = 'C';
    }
    if(y == g3[i])
    {
      gy = 'C';
    }
  }
  if(gx == gy)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}
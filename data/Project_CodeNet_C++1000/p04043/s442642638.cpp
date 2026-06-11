#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int five = 0, seven = 0;
  int data;
  for(int i = 0; i < 3; i++)
  {
    cin >> data;
    if(data==5)
    {
      five++;
    }
    else if(data==7)
    {
      seven++;
    }
  }

  if(five == 2 && seven == 1)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}

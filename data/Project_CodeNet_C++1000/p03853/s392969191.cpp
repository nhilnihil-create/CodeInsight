#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()	{
  int h, w;
  cin >> h >> w;
  char input[h][w];
  for (int i = 0; i < h; i++)	{
    for (int j = 0; j < w; j++)	{
      cin >> input[i][j];
    }
  }
  for (int i = 0; i < h; i++)	{
    for (int j = 0; j < w; j++)	{
      cout << input[i][j]; 
    }
    cout << endl;
    for (int j = 0; j < w; j++)	{
      cout << input[i][j]; 
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
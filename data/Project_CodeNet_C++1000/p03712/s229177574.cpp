#include <iostream>

using namespace std;

int main()	{
  long long h, w;
  cin >> h >> w;
  char img[h][w];
  for (long long i = 0; i < h; i++)	{
    for (long long j = 0; j < w; j++)	{
      cin >> img[i][j];
    }
  }
  for (int i = 0; i < w + 2; i++)	{
    cout << "#";
  }
  cout << endl;
  for (int i = 0; i < h; i++)	{
    cout << "#";
    for (int j = 0; j < w; j++)	{
      cout << img[i][j];
    }
    cout << "#";
    cout << endl;
  }
  for (int i = 0; i < w + 2; i++)	{
    cout << "#";
  }
  return 0;
}
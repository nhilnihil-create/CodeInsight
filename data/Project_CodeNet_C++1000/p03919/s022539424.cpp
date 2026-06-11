#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;
  string str;
  for(int i = 0; i < H; i++)
  {
    for(int j = 0; j < W; j++)
    {
      cin >> str;
      if(str == "snuke")
      {
        cout << (char)(j + 0x41) << i + 1 << endl;
        break;
      }
    }
  }
}
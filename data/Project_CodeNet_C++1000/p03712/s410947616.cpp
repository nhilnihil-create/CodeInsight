#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;
  
  string S;
  char s;
  
  for(int i = 0; i < H + 2; i++)
  {
    if(i == 0 || i == H + 1)
    {
      for(int j = 0; j < W + 2; j++)
      {
        S += "#";
      }
      cout << S << endl;
    }
    else
    {
      S += "#";
      for(int j = 0; j < W; j++)
      {
        cin >> s;
        S += s;
      }
      S += "#";
      cout << S << endl;
    }
    S = "";    
  }
}
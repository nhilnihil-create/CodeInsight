#include<bits/stdc++.h>
using namespace std;

int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> s(h*w);
  int i;
  for(i = 0; i < h*w; i++)
  {
    cin >> s.at(i);
  }
  for(i = 0; i < h*w; i++)
  {
    if(s.at(i) == "snuke")
    {
      int hh = i/w+1;
      char ww = i%w+65;
      cout << ww;
      cout << hh << endl;
      break;
    }
  }
}
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> img(h);
  
  for (int i = 0; i < h; i++)
      cin >> img.at(i);
  
  for (int i = 0; i < h*2; i++)
    cout << img.at(i/2) << endl;
}
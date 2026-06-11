#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n;
  string s;
  cin >> n;
  cin >> s;
  
  int x = 0;
  int max = 0;
  for(int i = 0; i < n; ++i)
  {
    if(s[i] == 'I')
    {
      x++;
      if(x > max) max = x;
    }
    else
    {
      x--;
    }
  }
  cout << max << endl;
}
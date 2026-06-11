#include<iostream>
#include<vector>
using namespace std;

int main()
{
  char c;
  
  vector<int> found(26);
  while (cin >> c)
  {
    if (found.at((int)c - 97) > 0)
    {
      cout << "no";
      return 0;
    }
    found.at((int)c - 97) ++;
  }
  
  cout << "yes";
  return 0;
}

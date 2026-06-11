#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int main()
{
  string a, b;
  cin >> a >> b;
  
  if (a.size() > b.size())
    cout << "GREATER";
  else if (a.size() < b.size())
    cout << "LESS";
  else
  {
    int s = a.size();
    bool flag = false;
    for (int i = 0; i < s; i ++)
    {
      if (a.at(i) > b.at(i))
      {
        cout << "GREATER";
        flag = true;
        break;
      }
      else if (a.at(i) < b.at(i))
      {
        cout << "LESS";
        flag = true;
        break;
      }
    }
    if (!flag) cout << "EQUAL";
  }
  
  return 0;
}

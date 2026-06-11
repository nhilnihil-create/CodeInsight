#include<iostream>
#include<string>
using namespace std;
int main()
{
  string o, e;
  string ans = "";
  cin >> o >> e;
  for(int i = 0; i < min(o.size(), e.size()); i++)
  {
    ans = ans + o[i] + e[i];
  }
  if(o.size() > e.size())
    ans = ans + o[o.size() - 1];
  else
  if(o.size() < e.size())
    ans = ans + e[e.size() - 1];
  cout << ans;
}

#include<iostream>
#include<string>
using namespace std;
int main()
{
  string s, p = "";
  cin >> s;
  for(int i = 0; i < s.size(); i++)
  {
    if(i % 2 == 0)
      p = p + s[i];
  }
  cout << p;
  return 0;
}
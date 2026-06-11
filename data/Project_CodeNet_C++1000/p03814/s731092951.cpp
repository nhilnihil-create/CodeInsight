#include<iostream>
#include<string>
#define rep(i, n) for (int i = 0; i < (n); i ++)
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  int n = s.size();
  int b = -1;
  int e = -1;
  
  rep(i, n)
  {
    if (s.at(i) == 'A' && b == -1) b = i;
    if (s.at(i) == 'Z') e = i;
  }
  
  cout << e - b + 1;
  return 0;
}

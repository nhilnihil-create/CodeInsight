#include<iostream>
#include<string>
#define rep(i, n) for (int i = 0; i < (n); ++ i)
using namespace std;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  
  int x = 0;
  int max = 0;
  rep(i, n)
  {
    if (s.at(i) == 'I') x ++;
    else if (s.at(i) == 'D') x --;
    
    if (x > max) max = x;
  }
  
  cout << max;
  return 0;
}

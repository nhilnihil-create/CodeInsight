#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin >> n;
  string s,t; cin >> s >> t;
  int hit = 0;
  for (int i = 0; i < n; i++)
  {
    int tmp = 0;
    for (int j = 0; j < n - i; j++)
    {
      int a = i + j;
      int b = n - i + j;
      if (s[a] == t[j])
      {
        tmp++;
        continue;
      }
      else 
      {
        tmp = 0;
        break;   
      }
    }
    hit = max(tmp, hit);
  }
  cout << 2 * n - hit << endl;
}
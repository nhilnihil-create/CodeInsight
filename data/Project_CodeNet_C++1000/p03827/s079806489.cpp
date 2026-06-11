#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int main()	{
  int n;
  string s;
  cin >> n;
  cin >> s;
  int a[n + 1];
  a[0] = 0;
  for (int i = 0; i < n; i++)	{
    a[i + 1] = a[i];
    if (s[i] == 'I')	{
      a[i + 1]++;
    }
    else	{
      a[i + 1]--;
    }
  }
  int max = 0;
  for (int i = 0; i < n + 1; i++)	{
    if (a[max] < a[i])	{
      max = i;
    }
  }
  cout << a[max] << endl;
  return 0;
}
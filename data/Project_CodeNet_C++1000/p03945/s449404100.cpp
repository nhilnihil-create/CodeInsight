#include <iostream>
#include <string>

using namespace std;

int main()	{
  string s;
  cin >> s;
  int n = s.length();
  int moves = 0;
  int tmp = 0;
  for (int i = 0; i < n - 1; i++)	{
  	if (s[i] != s[i + 1])	{
      tmp++;
    }
  }
  moves = tmp;
  for (int i = n - 1; i > 0; i--)	{
  	if (s[i] != s[i - 1])	{
      tmp++;
    }
  }
  moves = min(moves, tmp);
  cout << moves << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string text;
  cin >> text;

  // ２文字連続をはじく
  for (int i = 0; i < text.size() - 1; i++)
  {
    if (text[i] == text[i + 1])
    {
      cout << i + 1 << ' ' << i + 2 << endl;
      return 0;
    }
  }

  // ３文字中２文字をはじく
  for (int i = 0; i < text.size() - 2; i++)
  {
    if (text[i] == text[i + 2])
    {
      cout << i + 1 << ' ' << i + 3 << endl;
      return 0;
    }
  }

  // バランス
  cout << -1 << ' ' << -1 << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  int num[101] = {0};
  int a;
  for (int i = 0; i < 3; i++)
  {
    cin >> a;
    num[a]++;
  }

  int count = 0;
  for (int i = 1; i <= 100; i++)
  {
    if (num[i] != 0)
    {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
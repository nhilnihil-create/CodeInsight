#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  int N;
  cin >> N;
  int result = 0;
  for (int i = 1; i <= N; i++)
  {
    result += i;
  }

  cout << result << endl;

  return 0;
}
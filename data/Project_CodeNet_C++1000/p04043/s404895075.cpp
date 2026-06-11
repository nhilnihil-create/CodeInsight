#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

int main()
{
  int num[3];

  for (int i = 0; i < 3; i++)
    cin >> num[i];

  int cnt7 = 0, cnt5 = 0;

  for (int i = 0; i < 3; i++)
  {
    if (num[i] == 7)
      cnt7++;
    else if (num[i] == 5)
      cnt5++;
  }

  if (cnt7 == 1 && cnt5 == 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

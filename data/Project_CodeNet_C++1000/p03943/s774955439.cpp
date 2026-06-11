#include <bits/stdc++.h>

using namespace std;

int main()
{
  vector<int> n(3);

  for (int i = 0; i < 3; i++)
  {
    scanf("%d", &n[i]);
  }

  sort(n.begin(), n.end());

  cout << (n[2] == n[0] + n[1] ? "Yes" : "No");
}
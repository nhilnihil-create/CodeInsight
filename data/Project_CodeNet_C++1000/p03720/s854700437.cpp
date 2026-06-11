#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> V(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;

    V.at(--a)++;
    V.at(--b)++;
  }

  for (int i = 0; i < n; i++)
  {
    cout << V.at(i) << endl;
  }
}

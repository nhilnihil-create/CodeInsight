#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> v(100005, 0);
  for (int i = 0; i < n; i++)
  {
    int l, r;
    cin >> l >> r;
    for (int j = l; j <= r; j++)
    {
      v.at(j)++;
    }
  }
  int cnt = 0;
  for (int i = 0; i < 100005; i++)
  {
    if (v.at(i) != 0)
    {
      cnt++;
    }
  }
  cout << cnt << endl;
}

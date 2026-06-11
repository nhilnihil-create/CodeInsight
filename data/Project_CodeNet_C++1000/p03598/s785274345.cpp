#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, k, len = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    len += min((x - 0) * 2, abs(x - k) * 2);
  }
  cout << len << endl;
}

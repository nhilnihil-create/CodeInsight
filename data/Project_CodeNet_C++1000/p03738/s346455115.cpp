#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
#define MOD 1000000007

int main()
{
  string a, b;
  cin >> a >> b;
  if (a.size() > b.size())
  {
    cout << "GREATER" << endl;
    return 0;
  }
  else if (a.size() < b.size())
  {
    cout << "LESS" << endl;
    return  0;
  }
  if (a > b)
  {
    cout << "GREATER" << endl;
  }
  else if (a < b)
  {
    cout << "LESS" << endl;
  }
  else
  {
    cout << "EQUAL" << endl;
  }

  return 0;
}

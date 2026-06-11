#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  string s;
  cin >> s;
  bool N = false, W = false, S = false, E = false;
  rep(i, s.size())
  {
    switch (s.at(i))
    {
    case 'N':
      N = true;
      break;
    case 'W':
      W = true;
      break;
    case 'S':
      S = true;
      break;
    case 'E':
      E = true;
      break;
    default:
      break;
    }
  }
 // cout << N << S << " " << W << E << endl;
 // cout << (N ^ S) << " " << (W ^ E) << endl;
  if ((N ^ S) || (W ^ E))
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
  }
  return 0;
}
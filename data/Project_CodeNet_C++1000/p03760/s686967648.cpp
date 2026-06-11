#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long INF = 1LL << 60;

int main()
{
  string o, e;
  cin >> o >> e;
  rep(i, o.size())
  {
    cout << o[i];
    if(i < e.size())
      cout << e[i];
  }
}
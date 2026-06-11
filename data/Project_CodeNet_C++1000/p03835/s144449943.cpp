#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const long long INF = 1LL << 60;

int k,s;

int main()
{
  cin >> k >> s;
  int res = 0;
  for(int x = 0; x <= k; x++)
  {
    for(int y = 0; y <= k; y++)
    {
      int z = s-x-y;
      if(z >= 0 && z <= k) res++;
    }
  }
  cout << res << endl;
}
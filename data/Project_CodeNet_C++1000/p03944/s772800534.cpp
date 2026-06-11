#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
  int w, h, n;
  cin >> w >> h >> n;
  int l = 0, r = w, d = 0, u = h;
  
  rep(i,n)
  {
    int x, y, a;
    cin >> x >> y >> a;
    if(a == 1)
    {
      l = max(l, x);
    }
    else if(a == 2)
    {
      r = min(r, x);
    }
    else if(a == 3)
    {
      d = max(d, y);
    }
    else if(a == 4)
    {
      u = min(u, y);
    }
  }
  
  cout << max(0, r-l)*max(0, u-d) << endl;
  
  return 0;
}
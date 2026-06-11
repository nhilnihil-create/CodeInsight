#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   int w, h, n; cin >> w >> h >> n;
   int rong = w, cao = h;
   int l = 0, r = 0, b = 0, t = 0;
   for(int i = 0; i < n; i++)
   {
      int x, y, a; cin >> x >> y >> a;
      if(a==1)
         l = max(l, x);
      else if(a == 2)
         r= max(rong-x, r);
      else if(a==3)
         b = max(b,y);
      else
         t = max(cao - y, t);
   }
   w = w- l - r;
   h = h - t - b;
//   cout << w << " " << h << nl;
   if(w < 0 || h < 0)
   {
      cout << 0 << nl;
      return 0;
   }

   cout << w*h << nl;




	return 0;
}

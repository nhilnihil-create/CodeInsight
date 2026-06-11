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
   char ch[h+2][w+2];
   for(int i = 1; i <= h; i ++)
   {
      for(int j = 1; j <= w; j++)
         ch[i][j] = 'W';
   }

   for(int i = 0; i < n; i++)
   {
      int x, y, a; cin >> x >> y >> a;
      if(a == 1)
      {
         for(int i = 1; i <= h; i ++)
         {
            for(int j = 1; j <= x; j++)
               ch[i][j] = 'B';
         }
      }

      if(a == 2)
      {
         for(int i = 1; i <= h; i ++)
         {
         for(int j = x+1; j <= w; j++)
            ch[i][j] = 'B';
         }

      }

      if(a == 3)
      {
         for(int i = 1; i <= y; i++)
         {
         for(int j = 1; j <= w; j++)
            ch[i][j] = 'B';
         }

      }

      if(a == 4)
      {
         for(int i = y+1; i <= h; i ++)
         {
         for(int j = 1; j <= w; j++)
            ch[i][j] = 'B';
         }
      }

   }

   int ans = 0;
    for(int i = 1; i <= h; i ++)
   {
      for(int j = 1; j <= w; j++)
      {
         if(ch[i][j] == 'W')
            ans++;
      }
   }
   cout << ans << nl;





	return 0;
}

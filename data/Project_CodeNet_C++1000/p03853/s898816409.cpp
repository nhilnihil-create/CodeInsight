#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   int H, W; cin >> H >> W;
   char a[2*H+1][W+1];
   for(int i = 1; i <= H; i++)
   {
      for(int j = 1; j <= W; j++)
      {
         cin >> a[i][j];
      }
   }
   for(int i =1; i <= 2*H; i++)
   {
      for(int j = 1; j <= W; j++)
      {
         int k = floor((i+1)/2.0);
          cout <<  a[k][j];
      }
      cout << nl;
   }

	return 0;
}

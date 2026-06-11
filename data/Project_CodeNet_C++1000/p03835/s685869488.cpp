#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   long long ans = 0;
   int k, s; cin >> k >> s;
   for(int x = 0; x <= k; x++)
   {
      for(int y = 0; y <= k; y++)
      {
         if(s - x - y >= 0 && s - x - y <= k)
            ans++;
      }
   }
   cout <<ans << nl;
	return 0;
}

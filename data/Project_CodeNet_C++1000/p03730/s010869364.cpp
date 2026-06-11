#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;
const ll MOD = 1e9 + 7;
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   int a, b , c;
   cin >> a >> b >> c;
   for(int i = 1; i < 1000000; i++)
   {
      if(i*a % b == c)
      {
         cout << "YES" << nl;
         return 0;
      }
   }
   cout << "NO" <<nl;
   return 0;

}

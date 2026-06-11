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
   int n; cin >> n;
   int a[n+1];
   for(int i = 1; i <=n; i++)
      cin >> a[i];

   int ans = 0;
   int button = 1;
   int last = button;
   while(n--)
   {

      if(button ==2)
      {
         cout << ans << nl;
         return 0;
      }
      ans++;
      last = button;
      button = a[button];


   }
   cout << -1 << nl;

}

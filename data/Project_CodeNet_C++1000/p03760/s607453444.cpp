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
   string a, b; cin >> a >> b;
   string ans = "";
   reverse(all(a));
   reverse(all(b));
   int n = a.size() + b.size();
   for(int i = 1; i <= n ; i++)
   {
      if(i%2)
      {
         ans += a.back();
         a.pop_back();
      }
      else
      {
         ans += b.back();
         b.pop_back();
      }
   }
   cout << ans << nl;

}

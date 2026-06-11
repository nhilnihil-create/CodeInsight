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
   int w, a, b; cin >> w >> a >> b;
   int ans = max(a,b) - min(a,b) - w;
   if(ans < 0)
      cout << 0;
   else
      cout << ans << nl;
   return 0;

}

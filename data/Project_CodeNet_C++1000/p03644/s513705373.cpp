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
   int ans = 1;
   while(ans <= n)
      ans*=2;
   cout << ans/2 << nl;



   return 0;
}

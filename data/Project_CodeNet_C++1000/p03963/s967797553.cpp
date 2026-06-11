#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   string a, b, c;
   int n, k; cin >> n >> k;
   long long ans = k;
   for(long long i = 1; i < n; i++)
   {
      ans *= (k-1);
   }
   cout << ans << nl;







	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   int n;
   cin >> n;
   int a[n+1];
   int sum = 0;
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
      sum += a[i];
   }

   int m; cin >> m;
   for(int i = 0; i < m; i++)
   {
      int x, y; cin >> x >> y;
      cout << sum - a[x] + y << nl;
   }

	return 0;
}

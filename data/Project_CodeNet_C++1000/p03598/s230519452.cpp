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
   int n, k; cin >> n >> k;
   int a[n];
   for(int i = 0; i < n; i++)
      cin >> a[i];
   int sum = 0;
   for(int i = 0; i < n; i++)
   {
      int tmp = min(a[i], abs(k-a[i]));
      sum+= tmp;
   }
   cout << sum*2 << nl;

   return 0;
}

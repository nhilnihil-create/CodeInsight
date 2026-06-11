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
   ll n; cin >> n;
   int sum = 0;
   for(int i =0; i < n; i++)
   {
      int x, y; cin >> x >> y;
      sum += y-x+1;
   }
   cout <<sum << nl;
   return 0;
}

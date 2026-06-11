#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   long long a, b, x; cin >> a >> b >> x;
   long long ans =  b/x;
   int k = 1;
   while(k*x <a)
   {
      ans--;
      k++;
   }
   if(!a)
      ans++;
   cout << ans << nl;



	return 0;
}

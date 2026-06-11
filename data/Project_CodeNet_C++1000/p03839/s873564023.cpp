/*
 * Author : Andrew J
*/
#include <bits/stdc++.h>
using namespace std;
#define rall(x) x.rbegin() , x.rend()
#define all(x) x.begin() , x.end()
#define fi first
#define se second
#define pb push_back
using ll = long long;
using ii = pair <ll , ll>;
void in(ll &x);
const ll N = 1e5 + 10;
#define singleCase
// #define multipleCase
ll n,k,ps[N],pps[N],a[N];

ll rsum(ll l , ll r , ll pref[]) {
   return pref[r] - pref[l - 1];
}

void work() {
   in(n); in(k);
   ll sump = 0;
   for (ll i = 1 ; i <= n ; i++) {
      in(a[i]);
      ps[i] = ps[i - 1] + a[i];
      pps[i] = pps[i - 1] + max(a[i] , 0LL);
      sump += max(a[i] , 0LL);
   }
   ll sol = 0;
   for (ll i = 1 ; i <= n ; i++) {
      ll l = i, r = i + k - 1;
      if (r > n) break;
      ll cur = sump - rsum(l , r , pps) + max(rsum(l , r , ps) , 0LL);
      sol = max(sol , cur);
   }
   printf("%lld\n" , sol);
   return;
}

int main() {
   #ifdef multipleCase
      ll nQ; in(nQ);
      while (nQ--)
         work();
   #endif
   #ifdef singleCase
      work();
   #endif
   return 0;
}

void in(ll &x) {
	bool neg = false;
	register ll c;
	x = 0;
	c = getchar();
	if(c == '-') {
		neg = true;
		c = getchar();
	}
	for (; c > 47 && c < 58; c = getchar())
	  x = (x << 1) + (x << 3) + c - 48;
	if (neg) x *= -1;
}

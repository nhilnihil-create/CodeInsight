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
const ll N = 55;
#define singleCase
// #define multipleCase
ll n,p,a[N],dp[N][2];

ll f(ll cur , ll md) {
   if (cur > n) return md == p;
   ll &sol = dp[cur][md];
   if (sol != -1) return sol;
   return sol = f(cur + 1 , (md + a[cur]) % 2) + f(cur + 1 , md);
}

void work() {
   memset (dp , -1 , sizeof dp);
   in(n); in(p);
   for (ll i = 1 ; i <= n ; i++) {
      in(a[i]);
   }
   printf("%lld\n" , f(1 , 0));
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

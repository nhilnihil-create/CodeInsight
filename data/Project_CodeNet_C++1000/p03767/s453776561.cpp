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
const ll N = 3e5 + 10;
#define singleCase
// #define multipleCase
ll n,a[N];

void work() {
   in(n);
   for (ll i = 1 ; i <= n * 3 ; i++)
      in(a[i]);
   sort(a + 1 , a + n * 3 + 1);
   ll sol = 0;
   for (ll i = n * 3 - 1, t = 0 ; i >= 1 ; i -= 2, t++) {
      if (t == n) break;
      sol += a[i];
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

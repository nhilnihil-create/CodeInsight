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
const ll N = 2e5 + 10;
#define singleCase
// #define multipleCase
ll pos[N],n;

void work() {
   in(n);
   for (ll i = 1, x ; i <= n ; i++) {
      in(x);
      pos[x] = i;
   }
   ll sol = 0;
   set <ll> s;
   s.insert(0); s.insert(n + 1);
   for (ll i = 1 ; i <= n ; i++) {
      auto it = s.upper_bound(pos[i]);
      ll high = *it;
      --it;
      ll low = *it;
      ll k = min(pos[i] - low , high - pos[i]);
      sol += i * (k * (k + 1) + k * (high - low - 1 - 2 * k));
      s.insert(pos[i]);
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

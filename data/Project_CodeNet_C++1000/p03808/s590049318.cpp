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
// const ll N = ;
#define singleCase
// #define multipleCase
ll n;

ll modular(ll x , ll m) {
   return ((x % m) + m) % m;
}

void work() {
   in(n);
   vector <ll> v(n);
   ll sum = 0;
   for (ll i = 0 ; i < n ; i++) {
      in(v[i]);
      sum += v[i];
   }
   bool pos = sum % ((n * (n + 1)) / 2) == 0;
   ll opt = sum / ((n * (n + 1)) / 2);
   ll tota = 0, totb = 0;
   for (ll i = 0 ; i < n ; i++) {
      ll cur = v[(i + 1) % n] - v[i];
      if ((opt - cur) % n != 0) pos = false;
      ll a = (opt - cur) / n;
      ll b = opt - a;
      if (a < 0 || b < 0) pos = false;
      tota += a, totb += b;
   }
   if (tota != opt || totb != (n - 1) * opt) pos = false;
   puts(pos ? "YES" : "NO");
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

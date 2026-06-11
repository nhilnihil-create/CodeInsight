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
ll n,a,b;

void work() {
   in(n); in(a); in(b);
   if (a > b || (n == 1 && a != b)) {
      puts("0");
   } else {
      ll low = b, high = a;
      for (ll i = 1 ; i < n ; i++) {
         low += a;
         high += b;
      }
      printf("%lld\n" , high - low + 1);
   }
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

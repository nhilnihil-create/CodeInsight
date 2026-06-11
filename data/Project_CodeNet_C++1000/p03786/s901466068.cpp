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
ll n;
bool vis[N];

ll dfs(ll x , vector <ll> &v) {
   if (x < 0 || x >= v.size()) return 0;
   if (vis[x]) return 0;
   if (v[x] == 0) return 0;
   vis[x] = 1;
   return 1 + dfs(x - 1 , v) + dfs(x + 1 , v);
}

void work() {
   in(n);
   vector <ll> v(n);
   for (ll i = 0 ; i < n ; i++) {
      in(v[i]);
   }
   sort(all(v));
   v.pb(INT_MIN);
   ll cum = 0;
   vector <ll> r(n);
   for (ll i = 0 ; i < n ; i++) {
      cum += v[i];
      r[i] = cum * 2 >= v[i + 1];
   }
   printf("%lld\n" , dfs(n - 1 , r));
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

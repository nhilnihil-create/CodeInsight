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
using ii = pair <int , int>;
void in(int &x);
// const int N = ;
#define singleCase
// #define multipleCase
int n,k;

void work() {
   in(n); in(k);
   vector <int> v(n);
   bool pos = false;
   for (int i = 0 ; i < n ; i++) {
      in(v[i]);
      if (v[i] >= k) {
         pos = true;
      }
   }
   if (!pos) {
      puts("IMPOSSIBLE");
      return;
   }
   int g = v[0];
   for (int i = 1 ; i < n ; i++) {
      g = __gcd(g , v[i]);
   }
   if (k % g == 0) {
      puts("POSSIBLE");
   } else {
      puts("IMPOSSIBLE");
   }
   return;
}

int main() {
   #ifdef multipleCase
      int nQ; in(nQ);
      while (nQ--)
         work();
   #endif
   #ifdef singleCase
      work();
   #endif
   return 0;
}

void in(int &x) {
	bool neg = false;
	register int c;
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

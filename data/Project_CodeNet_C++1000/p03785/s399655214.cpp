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
const int N = 1e5 + 10;
#define singleCase
// #define multipleCase
int n,c,k,t[N];

void work() {
   in(n); in(c); in(k);
   for (int i = 0 ; i < n ; i++) {
      in(t[i]);
   }
   sort(t , t + n);
   int sol = 0;
   for (int i = 0 ; i < n ; ) {
      int j = i + 1;
      while (j < n) {
         if (j - i >= c) break;
         if (t[j] - t[i] > k) break;
         j++;
      }
      i = j, sol++;
   }
   printf("%d\n" , sol);
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

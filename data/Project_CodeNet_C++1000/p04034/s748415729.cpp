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
int n,m,mem[N];
bool pos[N];

void work() {
   fill (mem , mem + N , 1);
   pos[1] = 1;
   in(n); in(m);
   for (int i = 0, u , v ; i < m ; i++) {
      in(u); in(v);
      if (pos[u]) pos[v] = 1;
      mem[u]--;
      mem[v]++;
      if (mem[u] == 0) pos[u] = 0;
   }
   int sol = 0;
   for (int i = 1 ; i <= n ; i++) {
      sol += mem[i] > 0 && pos[i];
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

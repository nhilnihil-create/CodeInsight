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
int n;
bool rmark[N],mark[N],vis[N];

void dfs(int x , int elm , vector <int> &v) {
   if (x < 0 || x >= n) return;
   if (vis[x]) return;
   if (v[x] != elm) return;
   vis[x] = 1;
   dfs(x + 1 , elm , v);
   dfs(x - 1 , elm , v);
   return;
}

void work() {
   in(n);
   vector <int> inp(n);
   for (int i = 0 ; i < n ; i++) {
      in(inp[i]);
   }
   vector <int> v;
   for (int i = 0 ; i < n ; i++) {
      if (!vis[i]) {
         dfs(i , inp[i] , inp);
         v.pb(inp[i]);
      }
   }
   vector <int> r;
   for (int i = 1 ; i < v.size() ; i++) {
      if (v[i] > v[i - 1]) {
         r.pb(1);
      } else if (v[i] < v[i - 1]) {
         r.pb(2);
      } else {
         r.pb(3);
      }
   }
   if (n > 1 && r[0] == 3) r[0] = r[1];
   for (int i = 1 ; i < r.size() ; i++) {
      if (r[i] == 3) r[i] = r[i - 1];
      if (rmark[i]) continue;
      if (r[i] == 3 || r[i - 1] == 3) continue;
      if (r[i] != r[i - 1]) {
         rmark[i + 1] = 1;
         mark[i] = 1;
      }
   }
   mark[v.size()] = 1;
   int sol = 0;
   for (int i = 0 ; i <= v.size() ; i++) {
      sol += mark[i];
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

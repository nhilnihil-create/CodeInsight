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
using iii = pair <int , ii>;
using iiii = pair <ii , ii>;
void in(int &x);
const int N = 1e5 + 10;
const int inf = 1e9;
#define singleCase
// #define multipleCase
int n,m,dp[N][15],qryOrder[N][15];
vector <int> adj[N];
vector <iii> query;

int f(int u , int d) {
   if (d > 10) return inf;
   int &sol = dp[u][d];
   if (sol != -1) return sol;
   sol = inf;
   for (int i = d ; i <= 10 ; i++) {
      if (qryOrder[u][i] == -1) continue;
      sol = min(qryOrder[u][i] , sol);
   }
   for (int v : adj[u]) {
      sol = min(sol , f(v , d + 1));
   }
   return sol;
}

void inputAndInit() {
   memset (dp , -1 , sizeof dp);
   memset (qryOrder , -1 , sizeof qryOrder);
   in(n); in(m);
   for (int i = 0, u, v ; i < m ; i++) {
      in(u); in(v);
      adj[u].pb(v);
      adj[v].pb(u);
   }
   int q; in(q);
   query.resize(q);
   for (int i = 0, u, d , c ; i < q ; i++) {
      in(u); in(d); in(c);
      query[i] = {u , {d , c}};
   }
   reverse(all(query));
   for (int i = 0 ; i < query.size() ; i++) {
      int u = query[i].fi, d = query[i].se.fi, c = query[i].se.se;
      for (int j = 0 ; j <= d ; j++) {
         if (qryOrder[u][j] == -1) qryOrder[u][j] = i;
      }
   }
   return;
}

void work() {
   inputAndInit();
   for (int i = 1 ; i <= n ; i++) {
      int DP = f(i , 0);
      if (DP == inf) {
         puts("0");
      } else {
         printf("%d\n" , query[DP].se.se);
      }
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

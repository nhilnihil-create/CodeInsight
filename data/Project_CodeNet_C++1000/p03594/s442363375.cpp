#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 200005
#define eps 1e-12
//#define ivorysi
using namespace std;
typedef long long int64;
typedef unsigned int u32;
typedef double db;
template<class T>
void read(T &res) {
	res = 0;T f = 1;char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar();
	}
	res *= f;
}
template<class T>
void out(T x) {
	if(x < 0) {x = -x;putchar('-');}
	if(x >= 10) {
		out(x / 10);
	}
	putchar('0' + x % 10);
}
int H,W,d;
bool vis[1005][1005];
string s = "RBGY";
void Solve() {
	read(H);read(W);read(d);
	for(int i = 1 ; i <= H ; ++i) {
		for(int j = 1 ; j <= W ; ++j) {
			int t = 0;
			if((i + j - 1) / d & 1) t |= 2;
			if((i - j + 500 - 1) / d & 1) t |= 1;
			putchar(s[t]);
		}
		enter;
	}
}
int main() {
#ifdef ivorysi
	freopen("f1.in","r",stdin);
#endif
	Solve();
}

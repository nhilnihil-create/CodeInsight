#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 40005
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
string s;
int main() {
#ifdef ivorysi
	freopen("f1.in","r",stdin);
#endif
	cin >> s;
	if(s.substr(0,4) == "YAKI") puts("Yes");
	else puts("No");
}

#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 200005
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
	res = res * 10 +c - '0';
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
int H,W,h,w;
void Solve() {
    read(H);read(W);read(h);read(w);
    if(H % h != 0) {
	puts("Yes");
	for(int i = 0 ; i < H ; ++i) {
	    for(int j = 0 ; j < W ; ++j) {
		if(i % h == 0) {out(1000 * (h - 1) - 1);}
		else out(-1000);
		space;
	    }
	    enter;
	}
    }
    else if(W % w != 0) {
	puts("Yes");
	for(int i = 0 ; i < H ; ++i) {
	    for(int j = 0 ; j < W ; ++j) {
		if(j % w == 0) {out(1000 * (w - 1) - 1);}
		else out(-1000);
		space;
	    }
	    enter;
	}
    }
    else {
	puts("No");
    }
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}

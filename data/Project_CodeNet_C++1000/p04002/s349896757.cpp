#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 100005
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
int H,W,N;
int a[MAXN],b[MAXN];
int64 ans[MAXN];
map<pii,int> zz;
map<pii,int> cnt;
int dx[9] = {-1,1,0,0,0,1,1,-1,-1};
int dy[9] = {0,0,-1,1,0,1,-1,1,-1};
void Solve() {
    read(H);read(W);read(N);
    for(int i = 1 ; i <= N ; ++i) {
	read(a[i]);read(b[i]);
	zz[mp(a[i],b[i])] = 1;
    }
    for(int i = 1 ; i <= N ; ++i) {
	for(int k = 0 ; k < 9 ; ++k) {
	    int tx = a[i] + dx[k];
	    int ty = b[i] + dy[k];
	    if(tx > 1 && tx < H && ty > 1 && ty < W) {
		int c = 0;
		for(int h = 0 ; h < 9 ; ++h) {
		    if(zz[mp(tx + dx[h],ty + dy[h])]) ++c;
		}
		cnt[mp(tx,ty)] = c;
	    }
	}
    }
    ans[0] = 1LL * (H - 2) * (W - 2);
    for(auto t : cnt) {
	ans[0]--;
	ans[t.se]++;
    }
    for(int i = 0 ; i <= 9 ; ++i) {
	out(ans[i]);enter;
    }
}

int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}

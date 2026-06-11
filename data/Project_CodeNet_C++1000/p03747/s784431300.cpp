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
int N;
int64 T,x[MAXN],to[MAXN],ans[MAXN],L;
int id[MAXN],w[MAXN];
void Solve() {
    read(N);read(L);read(T);
    for(int i = 0 ; i < N ; ++i) {
	read(x[i]);read(w[i]);
	if(w[i] == 1) to[i] = (x[i] + T) % L;
	else to[i] = ((x[i] - T) % L + L) % L;
	id[i] = i;
    }
    sort(id,id + N,[](int a,int b){return to[a] < to[b] || (to[a] == to[b] && w[a] < w[b]);});
    int pos = 0;
    for(int i = 1 ; i < N ; ++i) {
	if(w[i] ^ w[0]) {
	    pos += (T / L) * 2 % N;
	    int64 rem = T % L;
	    int64 dis = x[i] - x[0];
	    if(w[0] == 2) dis = L - dis;
	    if(dis + L < 2 * rem) pos += 2;
	    else if(dis < 2 * rem) pos += 1;
	    pos %= N;
	}
    }
    if(w[0] == 1) pos %= N;
    else pos = (N - pos % N) % N;
    for(int i = 0 ; i < N ; ++i) {
	if(id[i] == 0) {
	    int p = i;
	    int cnt = 0;
	    while(cnt < N) {
		ans[pos] = to[id[p]];
		p = (p + 1) % N;
		pos = (pos + 1) % N;
		++cnt;
	    }
	}
    }
    for(int i = 0 ; i < N ; ++i) {
	out(ans[i]);enter;
    }
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}

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
int D,N,a[MAXN],cnt[MAXN];
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) {read(a[i]);cnt[a[i]]++;}
    for(int i = 1 ; i <= N ; ++i) D = max(D,a[i]);
    if(D & 1) {
        if(cnt[D / 2 + 1] != 2) {puts("Impossible");return;}
        int res = 0;
        for(int i = D / 2 + 1 ; i <= D ; ++i) {
            res += cnt[i];
            if(cnt[i] < 2) {puts("Impossible");return;}
        }
        if(res != N) {puts("Impossible");return;}
    }
    else {
        if(cnt[D / 2] != 1) {puts("Impossible");return;}
        int res = 1;
        for(int i = D / 2 + 1 ; i <= D ; ++i) {
            res += cnt[i];
            if(cnt[i] < 2) {puts("Impossible");return;}
        }
        if(res != N) {puts("Impossible");return;}
    }
    puts("Possible");return;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}

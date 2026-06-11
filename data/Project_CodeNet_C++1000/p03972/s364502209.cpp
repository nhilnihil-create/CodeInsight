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
int W,H;
int64 p[MAXN],q[MAXN],ans;
int id[2][MAXN],c[2];
void Solve() {
    read(W);read(H);
    for(int i = 0 ; i < W ; ++i) {
        id[0][i] = i;
        read(p[i]);
    }
    for(int i = 0 ; i < H ; ++i) {
        id[1][i] = i;
        read(q[i]);
    }
    sort(id[0],id[0] + W,[](int a,int b){return p[a] < p[b];});
    sort(id[1],id[1] + H,[](int a,int b){return q[a] < q[b];});
    int p1 = 0,p2 = 0;
    for(int i = 1 ; i <= W + H ; ++i) {
        if(p2 >= H || (p1 < W && p[id[0][p1]] < q[id[1][p2]])) {
            ans += 1LL * (H - c[1] + 1) * p[id[0][p1]];
            ++p1;++c[0];
        }
        else {
            ans += 1LL * (W - c[0] + 1) * q[id[1][p2]];
            ++p2;++c[1];
        }
    }
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}

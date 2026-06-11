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
int N,a[MAXN * 2],v[MAXN * 2];
bool check(int x) {
    for(int i = 1 ; i <= 2 * N - 1 ; ++i) {
        v[i] = (a[i] > x);
    }
    for(int i = 1 ; i < N ; ++i) {
        if(v[N - i] == v[N - i + 1]) {
            return v[N - i] != 1;
        }
        if(v[N + i] == v[N + i - 1]) {
            return v[N + i] != 1;
        }
    }
    v[N] ^= ((N - 1) & 1);
    return v[N] != 1;
}
void Solve() {
    read(N);
    for(int i = 1 ; i <= 2 * N - 1 ; ++i) read(a[i]);
    int L = 2,R = 2 * N - 2;
    while(L < R) {
        int mid = (L + R) >> 1;
        if(check(mid)) R = mid;
        else L = mid + 1;
    }
    out(L);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}

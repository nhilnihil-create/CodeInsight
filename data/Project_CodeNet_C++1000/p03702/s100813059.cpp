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
int64 B,A;
int64 h[MAXN];
void Solve() {
    read(N);read(A);read(B);
    for(int i = 1 ; i <= N ; ++i) {
        read(h[i]);
    }
    sort(h + 1,h + N + 1);
    int64 L = 0,R = 1000000000;
    while(L < R) {
        int64 mid = (L + R) >> 1;
        int64 rem = 0;
        for(int i = 1 ; i <= N ; ++i) {
            if(h[i] - mid * B > 0) rem += (h[i] - mid * B - 1) / (A - B) + 1;
        }
        if(rem <= mid) R = mid;
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

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
int N,K;
int64 pre[MAXN],suf[MAXN],a[MAXN],sum[MAXN];
void Solve() {
    read(N);read(K);

    for(int i = 1 ; i <= N ; ++i) {
        read(a[i]);
        sum[i] = sum[i - 1] + a[i];
        pre[i] = pre[i - 1];
        if(a[i] > 0) pre[i] = pre[i] + a[i];
    }
    for(int i = N ; i >= 1 ; --i) {
        suf[i] = suf[i + 1];
        if(a[i] > 0) suf[i] = suf[i] + a[i];
    }
    int64 ans = 0;
    for(int i = 1 ; i <= N ; ++i) {
        int r = i + K - 1;
        if(r > N) break;
        int64 all = pre[i - 1] + suf[r + 1];
        if(sum[r] - sum[i - 1] > 0) all += sum[r] - sum[i - 1];
        ans = max(ans,all);
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

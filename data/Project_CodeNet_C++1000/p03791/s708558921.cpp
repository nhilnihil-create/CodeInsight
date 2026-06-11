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
const int MOD = 1000000007;
int N,ans;
int x[MAXN];
int inc(int a,int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int mul(int a,int b) {
    return 1LL * a * b % MOD;
}
void update(int &x,int y) {
    x = inc(x,y);
}
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) read(x[i]);
    int pre = 0;
    int cnt = 0,ans = 1;
    for(int i = 1 ; i <= N ; ++i) {
        if(x[i] > pre) {++cnt;pre += 2;}
        else ans = mul(ans,cnt + 1);
    }
    for(int i = 1 ; i <= cnt ; ++i) ans = mul(ans,i);
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}

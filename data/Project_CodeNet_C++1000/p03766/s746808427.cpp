#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 1000005
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
int inc(int a,int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int mul(int a,int b) {
    return 1LL * a * b % MOD;
}
void update(int &x,int y) {
    x = inc(x,y);
}
int N;
int sum[MAXN],dp[MAXN];
void Solve() {
    read(N);
    dp[0] = 1;
    sum[0] = 1;
    int ans = 0;
    for(int i = 1 ; i <= N ; ++i) {
        update(dp[i],dp[i - 1]);
        if(i >= 3) update(dp[i],sum[i - 3]);
        sum[i] = inc(sum[i - 1],dp[i]);
    }
    for(int i = 0 ; i <= N ; ++i) {
        if(i == N - 1) {
            update(ans,mul(dp[i],N - 1));
        }
        else if(i == N) {
            update(ans,dp[i]);
        }
        else {
            update(ans,mul(dp[i],mul(N - 1,N - 1)));
        }
        if(i < N - 1) {
            int t = N - i - 1;
            update(ans,mul(dp[i],N - t));
        }
    }
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}

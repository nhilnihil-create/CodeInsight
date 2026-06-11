#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 5005
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
char s[5005];
int dp[5005][5005],N,L;

void Solve() {
    read(N);
    scanf("%s",s + 1);
    L = strlen(s + 1);
    dp[0][0] = 1;
    for(int i = 0 ; i < N ; ++i) {
	for(int j = 0 ; j <= N ; ++j) {
	    if(j == 0) update(dp[i + 1][j],dp[i][j]);
	    else update(dp[i + 1][j - 1],mul(dp[i][j],2));
	    update(dp[i + 1][j + 1],dp[i][j]);
	}
    }
    out(dp[N][L]);enter;
}

int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}

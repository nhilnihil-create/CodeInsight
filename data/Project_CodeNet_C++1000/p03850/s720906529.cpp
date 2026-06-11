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
int64 dp[MAXN][3];
int64 A[MAXN];
char op[MAXN][5];
void update(int64 &x,int64 y) {
    x = max(x,y);
}
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) {
	read(A[i]);
	if(i != N) scanf("%s",op[i] + 1);
    }
    dp[1][0] = A[1];
    dp[1][1] = -1e18;
    dp[1][2] = -1e18;
    for(int i = 2 ; i <= N ; ++i) {
	for(int j = 0 ; j < 3 ; ++j) dp[i][j] = -1e18;
	for(int j = 0 ; j < 3 ; ++j) {
	    int t = (op[i - 1][1] == '-');
	    int k = (t ^ j) & 1;
	    int64 d = A[i];
	    if(k) d = -A[i];
	    if(t && j < 2) update(dp[i][j + 1],dp[i - 1][j] + d);
	    for(int h = 0 ; h <= j ; ++h) update(dp[i][h],dp[i - 1][j] + d);
	}
    }
    out(dp[N][0]);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}

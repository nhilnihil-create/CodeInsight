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
int T[MAXN],A[MAXN];
int N;
int mul(int a,int b) {
    return 1LL * a * b % MOD;
}
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) read(T[i]);
    for(int i = 1 ; i <= N ; ++i) read(A[i]);
    int ans = 1;
    for(int i = 1 ; i <= N ; ++i) {
	if(T[i] != T[i - 1] || A[i] != A[i + 1]) {
	    int a = -1,b = -1;
	    if(T[i] != T[i - 1]) a = T[i];
	    if(A[i] != A[i + 1]) b = A[i];
	    if(a != -1 && b != -1) {
		if(a != b) {puts("0");return;}
	    }
	    if(b > T[i]) {puts("0");return;}
	    if(a > A[i]) {puts("0");return;}
	}
	else {
	    ans = mul(ans,min(A[i],T[i]));
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

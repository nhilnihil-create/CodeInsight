#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 1000005
#define eps 1e-10
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
	res = res * 10 + c - '0';
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
int64 A,B,C,D;
bool check(int64 a,int64 b) {
    return B - A >= a && B - A <= b;
}
void Solve() {
    read(N);read(A);read(B);read(C);read(D);
    for(int i = 0 ; i <= N - 1 ; ++i) {
	int64 u = (N - 1 - i) * D - C * i,d = (N - 1 - i) * C - C * i;
	if(check(d,u)) {puts("YES");return;}
	u = C * i - (N - 1 - i) * C,d = C * i - (N - 1 - i) * D;
	if(check(d,u)) {puts("YES");return;}
    }
    puts("NO");
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}

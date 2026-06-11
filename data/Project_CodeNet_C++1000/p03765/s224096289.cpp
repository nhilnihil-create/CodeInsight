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
char s[2][MAXN];
int Q;
int sum[2][MAXN];
void Solve() {
    scanf("%s%s",s[0] + 1,s[1] + 1);
    int l = strlen(s[0] + 1);
    for(int i = 1 ; i <= l ; ++i) {
	sum[0][i] = sum[0][i - 1];
	if(s[0][i] == 'A') sum[0][i] += 1;
	else sum[0][i] += 2;
    }
    l = strlen(s[1] + 1);
    for(int i = 1 ; i <= l ; ++i) {
	sum[1][i] = sum[1][i - 1];
	if(s[1][i] == 'A') sum[1][i] += 1;
	else sum[1][i] += 2;
    }
    read(Q);
    int a,b,c,d;
    for(int i = 1 ; i <= Q ; ++i) {
	read(a);read(b);read(c);read(d);
	if((sum[0][b] - sum[0][a - 1]) % 3 == (sum[1][d] - sum[1][c - 1]) % 3) {puts("YES");}
	else puts("NO");
    }
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}

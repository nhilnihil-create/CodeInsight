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
int64 aI,aO,aT,aJ,aL,aS,aZ;
int64 ans = 0;
void Solve() {
    read(aI);read(aO);read(aT);read(aJ);read(aL);read(aS);read(aZ);
    ans = aO;
    int64 t = min(aI,min(aJ,aL));
    ans += 3 * t;
    aI -= t;aJ -= t;aL -= t;
    ans += (aI / 2) * 2;aI %= 2;
    ans += (aJ / 2) * 2;aJ %= 2;
    ans += (aL / 2) * 2;aL %= 2;
    if(aI + aJ + aL >= 2) {
        if(t) {
            ans -= 3;ans += 4;
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

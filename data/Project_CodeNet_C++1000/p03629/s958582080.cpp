#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 200005
#define eps 1e-12
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
char a[MAXN];
int nxt[MAXN][26],N,dis[MAXN];
string ans = "";
void Solve() {
    scanf("%s",a + 1);
    N = strlen(a + 1);
    for(int i = 0 ; i < 26 ; ++i) nxt[N][i] = N + 1;
    for(int i = N - 1 ; i >= 0 ; --i) {
        for(int j = 0 ; j < 26 ; ++j) nxt[i][j] = nxt[i + 1][j];
        nxt[i][a[i + 1] - 'a'] = i + 1;
    }
    dis[N + 1] = 0;
    for(int i = N ; i >= 0 ; --i) {
        dis[i] = N + 1;
        for(int j = 0 ; j < 26 ; ++j) dis[i] = min(dis[nxt[i][j]] + 1,dis[i]);
    }
    int pos = 0;
    while(pos != N + 1) {
        for(int i = 0 ; i < 26 ; ++i) {
            if(dis[nxt[pos][i]] + 1 == dis[pos]) {
                ans += (i + 'a');
                pos = nxt[pos][i];
                break;
            }
        }
    }
    cout << ans << endl;
}
int main() {
#ifdef ivorysi
	freopen("f1.in","r",stdin);
#endif
    Solve();
}

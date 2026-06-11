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
char s[MAXN];
int num[MAXN];
void Solve() {
    read(N);
    scanf("%s",s);
    for(int i = 0 ; i <= 1 ; ++i) {
        for(int j = 0 ; j <= 1 ; ++j) {
            num[0] = i;num[1] = j;
            for(int k = 2 ; k < N ; ++k) {
                num[k] = (s[k - 1] == 'x') ^ num[k - 2] ^ num[k - 1];
            }
            int t0 = num[N - 1] ^ num[1] ^ num[0] ^ (s[0] == 'x');
            int tN = num[0] ^ num[N - 2] ^ num[N - 1] ^ (s[N - 1] == 'x');
            if(t0 == 0 && tN == 0) {
                for(int i = 0 ; i < N ; ++i) {
                    if(num[i] == 0) putchar('S');
                    else putchar('W');
                }
                enter;
                return;
            }
        }
    }
    puts("-1");
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define Max(_A,_B) (_A>_B?_A:_B)
#define Min(_A,_B) (_A<_B?_A:_B)
#define maxn 5007
#define md 1000000007
#define V e[i].v
#define ull unsigned long long
#define R register
int n, m, k, tot;
inline int read(){
    R int s = 0, f = 1; R char c = getchar();
        while (c > '9' || c < '0') { c = getchar();}
            while (c >= '0' && c <= '9') {s = s * 10 + c - '0'; c = getchar();}
                return s * f;
                }
char s[5007];
ll f[maxn][maxn], ans;   //f[i][j]表示i次操作构成序列j的 方案数
ll ksm(ll a, int b){
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % md;
        a = a * a % md;
        b >>= 1;
    }
    return res;
}
int main() {
    f[0][0] = 1ll;
    for (int i = 0; i <= 5000; i++)
        for (int j = 0; j <= 5000; j++) {
            if (f[i][j]){
                f[i + 1][j + 1] = (f[i + 1][j + 1] + 2ll * f[i][j] % md) % md;
                f[i + 1][Max(0, j - 1)] = (f[i + 1][Max(0, j - 1)] + f[i][j] % md) % md;
            }
        }
    scanf("%d\n%s", &n, s);
        m = strlen(s);
        ans = f[n][m];
        ans = (ans * ksm(ksm(2ll, m), md - 2)) % md;
        printf ("%lld\n", ans);
    return 0;
}
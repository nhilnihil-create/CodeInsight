
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
int64 a[MAXN],b[MAXN],pre[MAXN],ans[MAXN];
map<int,int64> zz,num;
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) {read(a[i]);b[i] = a[i];ans[1] += a[i];}
    sort(b + 1,b + N + 1);
    for(int i = N ; i >= 1 ; --i) {
 
        if(b[i] != b[i + 1]) {
            num[b[i]] += N - i;
            zz[b[i]] += zz[b[i + 1]];
        }
        num[b[i]]++;
        zz[b[i]] += b[i];
    }
    int pos = 1;
    for(int i = 1 ; i <= N ; ++i) {
        if(a[i] > pre[i - 1] && i != 1) {
            ans[i] += zz[pre[i - 1]] - pre[i - 1] * num[pre[i - 1]];
            ans[pos] -= ans[i];
            pos = i;
        }
        pre[i] = max(pre[i - 1],a[i]);
    }
    for(int i = 1 ; i <= N ; ++i) {
        out(ans[i]);enter;
    }
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}
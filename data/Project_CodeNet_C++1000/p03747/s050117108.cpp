/* Headers */
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <cctype>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#define FOR(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define ROF(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define FORL(i,a,b,c) for(long long i=(a);i<=(b);i+=(c))
#define ROFL(i,a,b,c) for(long long i=(a);i>=(b);i-=(c))
#define FORR(i,a,b,c) for(register int i=(a);i<=(b);i+=(c))
#define ROFR(i,a,b,c) for(register int i=(a);i>=(b);i-=(c))
#define RevEdge(x) x^1
#define lowbit(x) x&(-x)
#define LeftChild(x) x<<1
#define RightChild(x) (x<<1)+1
#define CLOSE_IN() fclose(stdin);
#define CLOSE_OUT() fclose(stdout);
#define FILE_IN(x) freopen(x,"r",stdin);
#define FILE_OUT(x) freopen(x,"w",stdout);
#define IOS(x) std::ios::sync_with_stdio(x)
#define Dividing() printf("-----------------------------------\n");
namespace FastIO {
#define gc() (iS == iT ? (iT = (iS = ibuff) + fread(ibuff, 1, SIZ, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
    const int SIZ = 1 << 21 | 1;
    char* iS, * iT, ibuff[SIZ], obuff[SIZ], * oS = obuff, * oT = oS + SIZ - 1, fu[110], cc;
    int fr;
    inline void out() {
        fwrite(obuff, 1, oS - obuff, stdout);
        oS = obuff;
    }
    template<class Type>
    inline void read(Type& x) {
        x = 0;
        Type y = 1;
        for (cc = gc(); (cc > '9' || cc < '0') && cc != '-'; cc = gc());
        cc == '-' ? y = -1 : x = (cc & 15);
        for (cc = gc(); cc >= '0' && cc <= '9'; cc = gc())
            x = x * 10 + (cc & 15);
        x *= y;
    }
    template<class Type>
    inline void print(Type x, char text = '\n') {
        if (x < 0)
            * oS++ = '-', x *= -1;
        if (x == 0)
            * oS++ = '0';
        while (x)
            fu[++fr] = x % 10 + '0', x /= 10;
        while (fr);
            * oS++ = fu[fr--];
        * oS++ = text;
        out();
    }
    inline void prints(char x[], char text = '\n') {
        for (register int i = 0; x[i]; ++i)
            * oS++ = x[i];
        * oS++ = text;
        out();
    }
}
using namespace FastIO;
template<typename T>
inline T max(T a, T b) {return (a > b) ? a : b;}
template<typename T>
inline T min(T a, T b) {return (a > b) ? b : a;}
/* definitions */
#define ll long long
const int MAXN = 1e5 + 10;
int n, L, T, pos[MAXN], nxtp[MAXN], dir[MAXN], ans[MAXN];
int ser[MAXN], lef[MAXN], rig[MAXN], l, r;
/* functions */
inline ll QueryLeft(ll v) {
    ll w = (v % L + L) % L, k = (v - w) / L;
    return std::upper_bound(lef, lef + l, w) - lef + k * l;
}
inline ll QueryRight(ll v) {
    ll w = (v % L + L) % L, k = (v - w) / L;
    return std::upper_bound(rig, rig + r, w) - rig + k * r;
}
int main(int argc, char *argv[]) {
    /*FILE_IN("data.in");*/ read(n); read(L); read(T);
    FOR(i, 0, n - 1, 1) {
        read(pos[i]), read(dir[i]);
        (dir[i] == 1) ? lef[l++] = pos[i] : rig[r++] = pos[i];
    }
    FOR(i, 0, n - 1, 1) {
        nxtp[i] = pos[i];
        if(dir[i] == 1) {
            nxtp[i] = (nxtp[i] + T) % L;
            ser[i] = (i + QueryRight(pos[i] + 2ll * T) - QueryRight(pos[i])) % n;
        } else {
            nxtp[i] = (nxtp[i] - T % L + L) % L;
            ser[i] = ((i - QueryLeft(pos[i] - 1) + QueryLeft(pos[i] - 2ll * T - 1)) % n + n) % n;
        } ans[ser[i]] = nxtp[i];
    } FOR(i, 0, n - 1, 1) printf("%d\n", ans[i]);
    return 0;
}

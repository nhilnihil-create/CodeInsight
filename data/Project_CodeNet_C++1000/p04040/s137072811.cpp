#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define inf 0x7f7f7f7f
#define maxn 100006
#define mod 1000000007
#define N 1
#define P 2


typedef long long ll;
typedef struct {
    int u, v, next, w;
} Edge;
Edge e[1];
int cnt, head[1];

inline void add(int u, int v,int w) {
    e[cnt].u = u;
    e[cnt].v = v;
    e[cnt].w = w;
    // e[cnt].f=f;
    e[cnt].next = head[u];
    head[u] = cnt++;
    e[cnt].u = v;
    e[cnt].v = u;
    e[cnt].w = w;
    //    e[cnt].f=-f;
    e[cnt].next = head[v];
    head[v] = cnt++;
}

inline void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
inline ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
ll h,w,a,b,f[2*100005],inv[2*100005];

ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
void solve(){
    f[0]=1;
    for(ll i=1;i<=h+w-2;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    inv[0]=1;
    inv[h+w-2]=qpow(f[h+w-2],mod-2);
    for(int i=h+w-3;i>0;i--)
        inv[i]=inv[i+1]*(i+1)%mod;

}
ll C(ll a,ll b){
    return f[a]*inv[b]%mod*inv[a-b]%mod;
}

int main(){
    h=read(),w=read(),a=read(),b=read();
    solve();
    ll res=0;
    for(int i=1;i<=h-a;i++){
        ll t=C(i-1+b-1,i-1)*C(h-i+w-b-1,h-i)%mod;
        res=(res+t)%mod;
    }
    cout<<res<<endl;
    return 0;
}

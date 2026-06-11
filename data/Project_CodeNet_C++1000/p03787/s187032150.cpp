#include<cstdio>
#include<algorithm>
#include<iostream>
#define rep(i,a,b) for(register int i = a; i <= b; i++)
using namespace std;

#define ll long long
const int N = 100000+10;
inline int read() { 
	int s = 0,t = 1; char c = getchar();
	while( !isdigit(c) ) { if( c == '-' ) t = -1; c = getchar(); }
	while( isdigit(c) ) s = s * 10 + c - 48, c = getchar();
	return s * t;
}

int fa[N], f[N];
bool vis[N], pd[N];
int cnt; ll ans;
inline int getfa(int x){
    if ( !fa[x] ) return x;
    int t = getfa(fa[x]);
    f[x] ^= f[fa[x]];
    return fa[x] = t;
}
int main(){
	int n, m, x, y, l, r;
    n = read(), m = read();
    rep(i,1,m){
        vis[x=read()] = vis[y=read()] = 1;
        l = getfa(x), r = getfa(y);
        if (l<r){
            swap(l,r);
            swap(x,y);
        }
        if ( l == r && f[x] == f[y]) pd[l]=1;
        if ( l == r ) continue;
        pd[fa[l] = r] |= pd[l];
        f[l] = f[x] ^ f[y] ^ 1;
    }
    rep(i,1,n) if (!vis[i]) cnt++;
    ans=(ll)cnt*(n-cnt)*2+(ll)cnt*cnt;
    cnt=0;
    rep(i,1,n) if (vis[i]&&!fa[i]) cnt++;
    ans+=(ll)cnt*cnt;
    cnt=0;
    /*fo(i,1,n)
        if (vis[i]&&fa[i]){
            y=getfa(i);
            if (!pd[y]&&f[i]!=f[y]) cnt++;
        }*/
    rep(i,1,n) if (vis[i]&&!fa[i]&&!pd[i]) cnt++;
    rep(i,1,n) if (vis[i]&&!fa[i]&&!pd[i]) ans+=(ll)cnt;
    printf("%lld\n",ans);
}
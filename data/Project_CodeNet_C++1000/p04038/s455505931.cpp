/*
    Author: zxy_hhhh
    date: 2020/03/12
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<iostream>
#define ll long long
inline ll rd() {
    ll _x=0;int _ch=getchar(),_f=1;
    for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
    if (_ch=='-'){_f=0;_ch=getchar();}
    for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
    return _f?_x:-_x;
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
#define maxn 2005
#define mod 1000000007
int n,K;
int f[maxn][maxn];
int fac[maxn*maxn],inv[maxn*maxn];
inline int C(int n,int m) {return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main() {
    n=rd();K=rd();
    if (K==1) {
        wrt(1,'\n');
        return 0;
    }
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<=n*K;i++) {
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i=1;i<=n*K;i++) {
        inv[i]=1ll*inv[i-1]*inv[i]%mod;
    }
    f[0][0]=1;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=i;j++) {
            f[i][j]=(f[i-1][j]+(j>0?1ll*f[i][j-1]*C(n*K-i-(j-1)*(K-1)-1,K-2)%mod*(n-j+1):0))%mod;
        }
    }
    wrt(f[n][n],'\n');
}
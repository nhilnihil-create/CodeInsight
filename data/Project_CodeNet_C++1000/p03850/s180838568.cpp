#include<bits/stdc++.h>
#define pa pair<int,int>
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
const int maxn=1e5+10;

inline char gc(){
	return getchar();
	static const int maxs=1<<16;static char buf[maxs],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxs,stdin),p1==p2)?EOF:*p1++;
}
inline ll rd(){
    ll x=0;char c=gc();bool neg=0;
    while(c<'0'||c>'9'){if(c=='-') neg=1;c=gc();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=gc();
    return neg?(~x+1):x;
}

int N,a[maxn],op[maxn];
ll f[maxn][3];

inline void upd(ll &a,ll b){a=max(a,b);}

int main(){
    //freopen("","r",stdin);
    N=rd();
    a[1]=rd();op[1]=1;
    for(int i=2;i<=N;i++){
        char s[5];scanf("%s",s);
        op[i]=(s[0]=='+')?1:-1;
        a[i]=rd();
    }
    CLR(f,-127);f[0][0]=0;
    for(int i=1;i<=N;i++){
        upd(f[i][0],f[i-1][0]+op[i]*a[i]),upd(f[i][0],f[i-1][1]-op[i]*a[i]),upd(f[i][0],f[i-1][2]+op[i]*a[i]);
        upd(f[i][1],f[i-1][2]+op[i]*a[i]);
        if(op[i]==-1){
            upd(f[i][1],f[i-1][0]+op[i]*a[i]);
            upd(f[i][2],f[i-1][1]-op[i]*a[i]);
        }
        upd(f[i][1],f[i-1][1]-op[i]*a[i]);
        upd(f[i][2],f[i-1][2]+op[i]*a[i]);
        // printf("~%d %d %d %d\n",i,f[i][0],f[i][1],f[i][2]);
    }
    printf("%lld\n",f[N][0]);
    return 0;
}
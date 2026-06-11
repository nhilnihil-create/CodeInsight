#include<cstdio>
#include<iostream>

#define int long long

const int mod=1e9+7;
const int maxn=1e5+10;

int h,w,a,b,ans;
int f[maxn<<1];

inline int read(){
    char ch=getchar();int x=0,f=1;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

inline int ksm(int x,int y){
    x%=mod;
    int res=1;
    while(y){
        if(y&1) (res*=x)%=mod;
        (x*=x)%=mod;
        y>>=1;
    }
    return res;
}

inline int get(int x1,int y1,int x2,int y2){
    int n=x2-x1+y2-y1,m=x2-x1;
    return ( f[n]*ksm( f[m]*f[n-m] , mod-2 ) )%mod;
}

signed main(){
    h=read(),w=read(),a=read(),b=read();
    f[0]=1;
    for(register int i=1;i<=(maxn<<1);i++)
        (f[i]=f[i-1]*i)%=mod;
    for(register int i=1;i<=h-a;i++){
        (ans+=get(1,1,i,b)*get(i,b+1,h,w))%=mod;
    }
    std::cout<<ans<<std::endl;
    return 0;
}
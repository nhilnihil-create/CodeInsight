#include <cstdio>
using namespace std;

const int maxn=2e3+5,pps=1e9+7;

int n,k,ans;
int f[maxn],fac[maxn*maxn],inv[maxn*maxn];

int read() {
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
    return x*f;
}

int quick(int a,int b) {
    int sum=1;
    while(b) {
        if(b&1)sum=1ll*sum*a%pps;
        a=1ll*a*a%pps;b>>=1;
    }
    return sum;
}

void prepare(int N) {
    fac[0]=inv[0]=1;
    for(int i=1;i<=N;i++)
        fac[i]=1ll*fac[i-1]*i%pps;
    inv[N]=quick(fac[N],pps-2);
    for(int i=N-1;i;i--)
        inv[i]=1ll*inv[i+1]*(i+1)%pps;
}

int C(int a,int b) {
    return 1ll*fac[a]*inv[b]%pps*inv[a-b]%pps;
}

int main() {
    n=read(),k=read()-1;
    if(!k) {puts("1");return 0;}
    prepare(n*k+n);f[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            f[j]=(f[j]+1ll*C(n*k+n-i-(j-1)*k-1,k-1)*f[j-1]%pps)%pps;
    ans=1ll*f[n]*fac[n]%pps;
    printf("%d\n",ans);
    return 0;
}
//2018.9.25 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y){
    x^=y^=x^=y;
}
inline int _abs(const res &x){
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y){
    return x>y?x:y;
}
inline int _min(const res &x,const res &y){
    return x<y?x:y;
}
const int kcz=1e9+7;
const int NN=2e3+10,KK=2e3+10,N=NN*KK+NN+KK;
namespace MAIN{
    inline int qpow(res x,res y,const res &kcz){
        res ans=1;
        while(y){
            if(y&1)ans=(LL)ans*x%kcz;
            x=(LL)x*x%kcz,y>>=1;
        }
        return ans%kcz;
    }
    int inv[N],fac[N];
    inline void pre(){
        inv[0]=inv[1]=fac[0]=fac[1]=1;
        for(res i=2;i<=N-10;i++)fac[i]=(LL)fac[i-1]*i%kcz,inv[i]=(LL)(kcz-kcz/i)*inv[kcz%i]%kcz;
        for(res i=2;i<=N-10;i++)inv[i]=(LL)inv[i-1]*inv[i]%kcz;
    }
    inline int C(const res &x,const res &y){
        return (LL)fac[x]*inv[y]%kcz*inv[x-y]%kcz;
    }
    int n,k;
    int dp[NN][KK];
    inline void add(res &x,const res &y){
        x+=y;
        x>=kcz?x-=kcz:1;
    }
    inline void MAIN(){
        pre();
        n=read(),k=read()-1;
        if(!k){puts("1");return;}
        dp[0][0]=1;
        for(res i=0;i<=n;i++)
            for(res j=i;j<=n;j++){
                if(i)add(dp[i][j],dp[i-1][j]);
                if(j)add(dp[i][j],(LL)dp[i][j-1]*C(i+j*k-1,k-1)%kcz);
            }
        printf("%d\n",(LL)dp[n][n]*fac[n]%kcz);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}
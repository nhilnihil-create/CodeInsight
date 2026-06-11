#include<iostream>
using namespace std ;
#define int unsigned long long
const int mxn = 8000005 ;
const int Mod = 1e9+7 ;
int frac[mxn], inv[mxn];
int f[2005][2005], n, k;
int power(int a, int b){
    int res=1, car=a; 
    while(b){
        if(b&1) (res*=car)%=Mod;
        (car*=car)%=Mod;
        b>>=1;
    }
    return res;
}
void init(){
    frac[0]=1 ;
    for(int i=1;i<mxn;++i) (frac[i]=frac[i-1]*i)%=Mod ;
    inv[mxn-1] = power(frac[mxn-1], Mod-2);
    for(int i=mxn-2;i>0;--i) inv[i]=(inv[i+1]*(i+1))%Mod ;
    inv[0] = 1 ;
}
int C(int n, int k){
    return ((frac[n]*inv[k]%Mod)*inv[n-k])%Mod ;
}
signed main(){
    init() ;
    cin>>n>>k;
    if(k==1) return puts("1"),0 ;
    f[0][0] = 1 ;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=i;++j)
            (f[i][j] = f[i-1][j]+(j?((((f[i][j-1]*(n-j+1))%Mod)*C(n*k-i-(j-1)*(k-1)-1, k-2))%Mod):(0)))%=Mod ;
    cout<<f[n][n]<<endl ;
}
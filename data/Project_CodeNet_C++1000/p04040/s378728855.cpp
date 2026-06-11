#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
typedef long long ll;
using namespace std;
const int maxn=201100;
const int mod=1000000000+7;
int h,w,a,b;
ll inv[maxn],F[maxn],Finv[maxn];

void init(){
    inv[1]=1;
    for(int i=2;i<maxn;i++){
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    }
    F[0]=1;
    Finv[0]=1;
    for(int i=1;i<maxn;i++){
        F[i]=F[i-1]*i%mod;
        Finv[i]=Finv[i-1]*inv[i]%mod;
    }
}

ll C(ll n,ll m){
    if(n<0||m<0||m>n) return 0;
    return F[n]*Finv[m]%mod*Finv[n-m]%mod;
}


int main(){
    init();
    scanf("%d%d%d%d",&h,&w,&a,&b);//2 3 1 1
    ll ans=0;
    for(int i=1;i<=h-a;i++){
        //cout<<b+i-2<<"  "<<i-1<<endl;
        //cout<<h+w-b-i-2<<" "<<w-b-1<<endl;
        ans=(ans+C(b+i-2,i-1)*C(h+w-b-i-1,w-b-1)%mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}

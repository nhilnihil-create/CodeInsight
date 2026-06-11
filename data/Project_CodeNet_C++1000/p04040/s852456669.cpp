#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 200000+5;
const int dx[] = {0,0,-1,1,-1,-1,1,1};
const int dy[] = {-1,1,0,0,-1,1,-1,1};
using namespace std;
LL factor[N];
LL PowMod(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1)
            res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
LL inv(LL x){
    return PowMod(x,MOD-2);
}
LL C(LL n,LL m){
    return factor[n]*inv(factor[m])%MOD*inv(factor[n-m])%MOD;
}
void init(){
    factor[0]=1;
    for(int i=1;i<=N;i++)
        factor[i]=(factor[i-1]*i)%MOD;
}
int main(){
    init();
    LL h,w,A,B;
    scanf("%lld%lld%lld%lld",&h,&w,&A,&B);
    LL res=0;
    for(LL i=B+1;i<=w;i++){
        LL temp=(C(i-1+h-A-1,h-A-1)*C(w-i+A-1,w-i))%MOD;
        res=(res+temp)%MOD;
    }
    printf("%lld\n",res);
    return 0;
}

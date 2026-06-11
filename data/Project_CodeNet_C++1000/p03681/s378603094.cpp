#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
LL n,m;
scanf("%lld %lld",&n,&m);
if(abs(n-m)<=1){
    if(abs(n-m)==0){
        LL sum1=1,sum2=1;
        for(LL i=1;i<=n;++i){
            sum1=(sum1*i)%MOD;
        }
        for(LL i=1;i<=m;++i){
            sum2=(sum2*i)%MOD;
        }
        printf("%lld",(2*sum1*sum2)%MOD);
    }
    else{
        LL sum1=1,sum2=1;
        for(LL i=1;i<=n;++i){
            sum1=(sum1*i)%MOD;
        }
        for(LL i=1;i<=m;++i){
            sum2=(sum2*i)%MOD;
        }
        printf("%lld",(sum1*sum2)%MOD);
    }
}
else{
    printf("0");
}


    return 0;
}

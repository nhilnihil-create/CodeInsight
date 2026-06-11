/// You just can't beat the person who never gives up
/// ICPC next year

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+5 ;

int n ,k ,a[N] ;
long long cum[N] ,pos[N] ;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        if(a[i]>0) pos[i] = a[i] + pos[i-1] ;
        else pos[i] = pos[i-1] ;
        cum[i] = a[i] + cum[i-1] ;
    }
    long long ans = 0 ;
    for(int i=1;i+k-1<=n;++i){
        long long curpos = pos[i+k-1] - pos[i-1] ;
        long long allpos = pos[n] ;
        long long cursum = cum[i+k-1] - cum[i-1] ;
       // cout << i << " " << i+k-1 << " " << allpos << " " << curpos << " " << cursum << endl ;
        ans = max(ans ,allpos-curpos);
        ans = max(ans ,cursum + allpos-curpos);
    }
    printf("%lld\n",ans);
    return 0;
}

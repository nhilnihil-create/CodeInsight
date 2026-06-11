/// You just can't beat the person who never gives up
/// ICPC next year

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+5 ;

int n ,m ,a[N] ;
long long add[N] ,extra[N] ,ad ,cur ,ans ;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",a+i);
        if(!i) continue ;
        if(a[i]>=a[i-1]) ans += a[i] - a[i-1] ;
        else ans += a[i]+m - a[i-1] ;
        if(a[i]-a[i-1]>1){
            ++add[a[i-1]+2] ;
            extra[a[i]+1] -= a[i] - a[i-1] - 1;
            --add[a[i]+1] ;
        }
        else if(a[i]<a[i-1]){
            if(a[i-1]<=m-2){
                ++add[a[i-1]+2] ;
                ++add[1] ;
                extra[1] += m - a[i-1] - 1 ;
            }
            else if(a[i-1]==m-1) ++add[1] ;
            else ++add[2] ;
            extra[a[i]+1] -= a[i]+m - a[i-1] - 1 ;
            --add[a[i]+1] ;
        }
    }
    long long mx = 0 ;
    for(int i=1;i<=m;++i){
        ad += add[i] ;
        cur += ad + extra[i] ;
        mx = max(mx ,cur);
    }
    printf("%lld",ans-mx);
    return 0;
}

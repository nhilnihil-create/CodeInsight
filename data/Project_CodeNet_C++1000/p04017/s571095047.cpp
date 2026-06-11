/// You just can't beat the person who never gives up
/// ICPC next year

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+5 ;

int n ,l ,q ,x[N] ,nxt[N] ,lst[N] ;
int main(){
    scanf("%d",&n);
    int sq = sqrt(n) ;
    for(int i=1;i<=n;++i) scanf("%d",x+i);
    scanf("%d",&l);
    for(int i=1;i<=n;++i){
        int st = i ,en = n ;
        while(st<en){
            int mid = (st+en+1)/2 ;
            if(x[mid]-x[i]>l) en = mid-1 ;
            else st = mid ;
        }
        nxt[i] = st ;
    }
    for(int i=1;i<=n;++i){
        int cur = i ;
        for(int j=0;j<sq;++j){
            if(cur==n){
                cur = 1e9+5 ;
                break ;
            }
            cur = nxt[cur] ;
        }
        lst[i] = cur ;
    }
    lst[n] = 1e9+5 ;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b) swap(a,b);
        if(a==b){
            puts("0");
            continue ;
        }
        int ans = 0 ;
        while(lst[a]<=b){
            a = lst[a] ;
            ans += sq ;
        }
        while(a<b){
            ++ans ;
            a = nxt[a] ;
        }
        printf("%d\n",ans);
    }
    return 0;
}

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 100006
#define int long long
int A[MAXN];
int p[63][MAXN] , ans[MAXN] , Ans[MAXN] , d[MAXN];
int n , m; long long k;
main() {
    cin >> n;
    for( int i = 1 ; i <= n ; ++ i ) scanf("%lld",&A[i]) , d[i] = A[i] - A[i-1];
    cin >> m >> k;
    for( int i = 1 ; i <= n ; ++ i ) p[0][i] = i , Ans[i] = i;
    for( int i = 1 ; i <= m ; ++ i ) {
        scanf("%lld",&A[i]);
        swap( p[0][A[i]] , p[0][A[i]+1] );
    }
    for( int t = 1 ; t < 63 ; ++ t )
        for( int i = 1 ; i <= n ; ++ i ) 
            p[t][i] = p[t-1][p[t-1][i]];
    int c = k;
    for( int k = 62 ; k >= 0 ; -- k ) if( ( 1LL << k ) <= c ) {
        c -= ( 1LL << k );
        for( int i = 1 ; i <= n ; ++ i )
            Ans[i] = p[k][Ans[i]];
    }
    for( int i = 1 ; i <= n ; ++ i )
        ans[i] = d[Ans[i]];
    int as = 0;
    for( int i = 1 ; i <= n ; ++ i ) as += ans[i] , printf("%lld\n",as);
}
/*
5
1 3 6 10 15
2
10
3 4
*/
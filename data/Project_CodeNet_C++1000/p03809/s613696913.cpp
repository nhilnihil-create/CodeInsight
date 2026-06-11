#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define xx first
#define yy second
#define i64 long long int
#define MEM(a,x) memset(a,x,sizeof(x))
#define INF 1000000000
#define mod 998244353

using namespace std ;

typedef pair<int,int> pi ;

#define maxn 1000005

i64 a[maxn] , c[maxn] ;
vector <i64> g[maxn] ;

void dfs( i64 u, i64 par )
{
    if( g[u].size()==1 )
    {
        c[u] = a[u] ;
        return ;
    }

    i64 i , j , v , mx = 0LL , sum = 0LL  ;

    for(i=0 ; i<g[u].size() ; i++)
    {
        v = g[u][i] ;
        if( v==par ) continue ;
        dfs(v,u) ;
        sum += c[v] ;
        mx = max(c[v],mx) ;
    }
    i64 x = sum - a[u] ;
    if( x<0 || x > min( a[u] , min( sum-mx , sum/2 ) ) )
    {
        printf("NO\n") ;
        exit(0) ;
    }
    c[u] = a[u] - x ;
}

int main()
{
    i64 i , j , k , l , m , n ;

    scanf("%lld",&n) ;

    for(i=1 ; i<=n ; i++) scanf("%lld",&a[i]) ;

    for(i=1 ; i<n ; i++)
    {
        i64 u , v ;
        scanf("%lld %lld",&u,&v) ;
        g[u].pb(v) ; g[v].pb(u) ;
    }

    if( n==2 )
    {
        if( a[1]==a[2] ) printf("YES\n") ;
        else printf("NO\n") ;
        return 0 ;
    }

    i64 id = 1;

    for(i=2 ; i<=n ; i++)
    {
        if( g[i].size() > g[id].size() ) id = i ;
    }

    dfs(id,0) ;

    if( c[id]==0 ) printf("YES\n") ;
    else printf("NO\n") ;

    return 0 ;
}

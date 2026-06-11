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

#define maxn 100005

vector <int> g[maxn] ;
int vis[maxn] , qc[maxn] , ans[maxn] , qd[maxn] , qv[maxn] ;

int main()
{
    int i , j , k , l , m , n , q ;

    memset(vis,-1,sizeof(vis)) ;
    memset(ans,0,sizeof(ans)) ;

    scanf("%d %d",&n,&m) ;

    for(i=1 ; i<=m ; i++)
    {
        int u , v ;
        scanf("%d %d",&u,&v) ;
        g[u].pb(v) ; g[v].pb(u) ;
    }

    scanf("%d",&q) ;
    for(i=1 ; i<=q ; i++)
    {
        scanf("%d %d %d",&qv[i],&qd[i],&qc[i]) ;
    }

    for(i=q ; i>=1 ; i--)
    {
        if( vis[qv[i]] >= qd[i] ) continue ;

        queue < int > Q ;

        Q.push( qv[i] ) ;
        vis[ qv[i] ] = qd[i] ;

        while( !Q.empty() )
        {
            int u = Q.front() ;
            int d = vis[u] ;
            Q.pop() ;

            if( ans[u]==0 ) ans[u] = qc[i] ;

            for(j=0 ; j<g[u].size() ; j++)
            {
                int v = g[u][j] ;
                if( vis[v] < d-1 )
                {
                    vis[v] = d-1 ;
                    Q.push( v ) ;
                }
            }
        }
    }

    for(i=1 ; i<=n ; i++) printf("%d\n",ans[i]) ;

    return 0 ;
}

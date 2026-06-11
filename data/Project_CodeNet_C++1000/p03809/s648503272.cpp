#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007LL
#define IN freopen("pieaters.in","r",stdin)
#define OUT freopen("pieaters.out","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG pf("Hi\n")
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define off 2

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<i64, i64> pii;

#define INF 2000000000
#define alpha 26

#define maxn 300010
#define LOG 18

vector <int> g[maxn] ;

i64 a[maxn] ;
int fl = 1 ;

void dfs( int u , int par )
{
    vector <int> vec ;

    i64 sum = 0 ;
    for(int v: g[u])
    {
        if( v==par ) continue ;
        dfs(v,u) ;
        vec.pb( a[v] ) ;
        sum += a[v] ;
    }
    sort(vec.begin(),vec.end()) ;
    reverse(vec.begin(),vec.end()) ;

    if(vec.size()==0) return ;

    if( vec.size() == 1 )
    {
        if( vec[0] != a[u] )
        {
            printf("NO\n") ;
            exit(0) ;
        }
        return ;
    }

    i64 x = sum - a[u] , y = a[u] - x ;

    if( sum-vec[0] < x || x<0 || y<0 )
    {
        printf("NO\n") ;
        exit(0) ;
    }
    a[u] = y ;

    return ;
}

int main()
{
    int n ;

    scanf("%d",&n) ;
    for(int i=1 ; i<=n ; i++) scanf("%lld",&a[i]) ;

    for(int i=1 ; i<n ; i++)
    {
        int u , v ;
        scanf("%d %d",&u,&v) ;
        g[u].pb(v) ; g[v].pb(u) ;
    }

    int root = 0 ;

    if( n==2 )
    {
        if( a[1] == a[2] ) printf("YES\n") ;
        else printf("NO\n") ;
        return 0 ;
    }

    for(int i=1 ; i<=n ; i++)
    {
        if( (int)g[i].size() > 1 ) root = i ;
    }

    dfs(root,0) ;

    if( a[root] == 0 ) printf("YES\n") ;
    else printf("NO\n") ;

    return 0 ;
}

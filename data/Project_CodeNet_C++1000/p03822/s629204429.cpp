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

#define maxn 100010
#define LOG 18

vector <int> g[maxn] ;

int dfs(int u)
{
    vector <int> depths ;
    for(int v:g[u])
    {
        depths.pb( dfs(v) ) ;
    }
    sort( depths.begin() , depths.end() ) ;
    int sz = (int)depths.size() ;
    int res = 0 ;
    for(int i=sz-1 , j=1 ; i>=0 ; j++,i--)
    {
        res = max( res , depths[i]+j ) ;
    }
    return res ;
}

int main()
{
    int n ;
    scanf("%d",&n) ;

    for(int i=2 ; i<=n ; i++)
    {
        int u ;
        scanf("%d",&u) ;
        g[u].pb(i) ;
    }

    printf("%d\n",dfs(1)) ;

    return 0 ;
}

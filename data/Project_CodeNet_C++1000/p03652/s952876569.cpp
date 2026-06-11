#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("hard1.txt","r",stdin)
#define OUT freopen("hard1.txt","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG printf("Hi\n")
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define off 1000005
#define FastIO  ios_base::sync_with_stdio(false); cin.tie(NULL)


using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<i64, i64> pii ;

#define maxn 1000005
#define mod 1000000007LL
#define lim 1000000000
#define INF 4500000000000000000LL

int a[305][305] ;
int yes[305] , cnt[305] ;

int main()
{
    int n , m ;
    scanf("%d %d",&n,&m) ;

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=m ; j++) scanf("%d",&a[i][j]) ;
    }

    int ans = n ;

    for(int i=1; i<=m ; i++) yes[i] = 1 ;

    for( ; ; )
    {
        memset(cnt,0,sizeof(cnt)) ;
        int fl = 0 ;
        for(int i=1 ; i<=m ; i++)
        {
            if(yes[i]) fl = 1 ;
        }
        if(!fl) break ;
        for(int i=1; i<=n ; i++)
        {
            for(int j=1 ; j<=m ; j++)
            {
                if(yes[ a[i][j] ])
                {
                    cnt[ a[i][j] ]++ ;
                    break ;
                }
            }
        }
        int mx = 0 ;
        for(int i=1 ; i<=m ; i++) mx = max(cnt[i],mx) ;
        ans = min(mx,ans) ;
        for(int i=1 ; i<=m ; i++)
        {
            if( cnt[i]==mx ) yes[i] = 0 ;
        }
    }

    printf("%d\n",ans) ;

    return 0 ;
}

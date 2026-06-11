#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007LL
#define IN freopen("C.in","r",stdin)
#define OUT freopen("output.txt","w",stdout)
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

#define maxn 300005
#define INF 2000000000
#define alpha 26

int a[maxn] , b[maxn] ;

bool f(int x , int n)
{
    for(int i=1 ; i<=n ; i++)
    {
        if(a[i]<x) b[i] = 0 ;
        else b[i] = 1 ;
    }

    int m = (n+1)/2 ;

    if(b[m] == b[m+1] || b[m] == b[m-1]) return b[m] ;

    bool fl = 0 ;
    for(int i=1 ; i<n ; i++)
    {
        if(b[i] == b[i+1]) fl = 1 ;
    }

    if(fl==0)
    {
        if( (m-1)%2==1 ) return (b[m]^1) ;
        else return b[m] ;
    }

    int r = 2*n , l = 2*n ;

    for(int i=m+1 , j=1 ; i<n ; i++,j++)
    {
        if( b[i]==b[i+1] )
        {
            r = j ;
            break ;
        }
    }

    for(int i=m-1,j=1 ; i>1 ; i--,j++)
    {
        if(b[i] == b[i-1] )
        {
            l = j ;
            break ;
        }
    }

    if(l<r) return b[m-l] ;
    else return b[m+r] ;
}

int main()
{
    int n ;

    scanf("%d",&n) ;

    n = 2*n - 1 ;

    for(int i=1; i<=n ; i++) scanf("%d",&a[i]) ;

    int lo = 1 , hi = n ;

    while( lo < hi )
    {
        int mid = (lo+hi+1)/2 ;

        int ret = f(mid,n) ;

  //      printf("%d %d\n",mid,ret) ;

        if( ret ) lo = mid ;
        else hi = mid - 1 ;
    }

    printf("%d\n",lo) ;

    return 0 ;
}

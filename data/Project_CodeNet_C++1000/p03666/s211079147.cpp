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

bool f( int n , i64 c , i64 d , vector <i64> &v , i64 toMake )
{
    i64 tot = 0 ;
    for(int i=1; i<=n ; i++)
    {
        v.pb(d) ;
        tot += d;
    }
    if(tot < toMake) return false ;

    tot -= toMake ;

    int idx = -1 ;

    for(int i=n-1 ; i>=0 ; i--)
    {
        if( tot - 2*d >= 0 )
        {
            tot -= 2*d ;
            v[i] = -d ;
        }
        else{
            if( tot <= (d-c) || tot >= d+c )
            {
                v[i] -= tot ;
                return true ;
            }
            else{
                idx = i ;
                break ;
            }
        }
    }

    if( tot <= 1LL*(idx+1)*(d-c) )
    {
        for(int i=0 ; i<=idx && tot != 0 ; i++)
        {
            i64 ret = min(d-c,tot) ;
            tot -= ret ;
            v[i] -= ret ;
        }
        return true ;
    }
    v[idx] -= (d+c) ;
    tot -= (d+c) ;

    if( 1LL*(n-1-idx)*(d-c) + tot >= 0 )
    {
        for(int i=idx+1 ; i<n && tot!=0 ; i++)
        {
            i64 ret = min( -tot , d-c ) ;
            tot += ret ;
            v[i] += ret ;
        }
        return true ;
    }
    return false ;
}

i64 a[maxn] ;

int main()
{
    int n ;
    i64 A , B , C , D ;
    scanf("%d %lld %lld %lld %lld",&n,&A,&B,&C,&D) ;

    vector <i64> v ;

    bool res = f(n-1,C,D,v,abs(A-B)) ;

    if(!res) printf("NO\n") ;
    else
    {
        printf("YES\n") ;
   /*     a[1] = A ; a[n] = B ;
        for(int i=1 ; i<n ; i++) a[i+1] = a[i] + v[i-1] ;
        for(int i=1 ; i<=n ; i++) printf("%lld ",a[i]) ;
        printf("\n") ; */
    }

    return 0 ;
}

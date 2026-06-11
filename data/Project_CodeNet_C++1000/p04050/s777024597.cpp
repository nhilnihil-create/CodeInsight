#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define IN freopen("perimetric_chapter_1_input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)

#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG printf("Hi\n")
#define i64 long long int
#define ui64 unsigned long long int
#define xx first
#define yy second
//#define ln 17
#define off 2

#define sq(x) ((x)*(x))

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace __gnu_pbds;
using namespace std ;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<int,int> pii;

#define log 20
#define mod 1000000007LL
#define INF 2000000000
#define maxn 500005

const long double eps = 1e-9 ;

int a[505] , b[505] ;

int main()
{
    int n , m ;

    scanf("%d %d",&m,&n) ;

    int oddcount = 0 ;

    for(int i=1 ; i<=n ; i++)
    {
        scanf("%d",&a[i]) ;
        if( a[i]%2 == 1 ) oddcount++ ;
    }

    if(oddcount>=3)
    {
        printf("Impossible\n") ;
        return 0 ;
    }

    for(int i=1 ; i<=n ; i++)
    {
        if(a[i]%2==1)
        {
            swap(a[1],a[i]) ;
            break ;
        }
    }

    for(int i=2 ; i<=n ; i++)
    {
        if(a[i]%2 == 1)
        {
            swap(a[i],a[n]) ;
        }
    }

    vector <int> b ;

    if(n>1)
    {
        b.pb(a[1]+1) ;
        for(int i=2 ; i<n ; i++)
        {
            b.pb( a[i] ) ;
        }
    }
    else{
        b.pb(1) ;
    }

    if(a[n]!=1)
    {
        b.pb(a[n]-1) ;
    }

    for(int i=1 ; i<=n ; i++) printf("%d ",a[i]) ;
    printf("\n") ;

    printf("%d\n",b.size()) ;
    for(int x:b) printf("%d ",x) ;
    printf("\n") ;

    return 0 ;
}

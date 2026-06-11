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
#define INF 1000000000
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define off 8002

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<int, int> pii;

#define maxn 200005

int ask(i64 n)
{
    printf("? %lld\n",n) ;
    fflush(stdout) ;
    char s[5] ;
    scanf("%s",s) ;
    return (s[0]=='Y') ;
}

int findLength1()
{
    i64 st = 1 ;
    int len = 0 ;

    while( 1 )
    {
        int res = ask(st) ;
        if( res )
        {
            len++ ;
            st = st*10 ;
        }
        else break ;
    }
    return len ;
}

int findLength2()
{
    i64 st = 9 ;
    int len = 0 ;
    while( 1 )
    {
        int res = ask(st) ;
        len++ ;
        if( res == 0 )
        {
            st = st*10 + 9 ;
        }
        else break ;
    }
    return len ;
}

int main()
{
    int res = ask(555555555555LL) ;

    int len ;

    if(res) len = findLength2() ;
    else len = findLength1() ;

    i64 lo = 1 , hi ;

    for(int i=1 ; i<len ; i++) lo = lo*10 ;

    hi = 10*lo - 1 ;

//    printf("%d %lld %lld\n",len,lo,hi) ;

    while( lo < hi )
    {
        i64 mid = (lo+hi)/2 ;

        int res = ask(mid*10) ;

        if(res) hi = mid ;
        else lo = mid+1 ;
    }

    printf("! %lld\n",lo) ;

    return 0 ;
}

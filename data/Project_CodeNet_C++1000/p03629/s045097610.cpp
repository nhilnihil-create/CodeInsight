#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007
#define IN freopen("nocross.in","r",stdin)
#define OUT freopen("nocross.out","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG pf("Hi\n")
#define INF 1000000000000000000LL
#define i64 long long int
#define xx first
#define yy second
#define ln 17
#define off 2


using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const double eps = 1e-9 , pi = acos(-1.0);

#define maxn 200005

int Next[26][maxn] ;
int dp[maxn] , ch[maxn] ;

char s[maxn] , ans[maxn] ;

const int l = 26 ;

int main()
{
    int i , j , k , m , n ;

    scanf("%s",s) ;

    n = strlen(s) ;

    for( i=0 ; i<l ; i++ ) Next[i][n] = n ;

    for(i=n-1 ; i>=0 ; i--)
    {
        for(j=0 ; j<l ; j++) Next[j][i] = Next[j][i+1] ;
        Next[ s[i]-'a' ][i] = i ;
    }

    dp[n] = 1 ; dp[n+1] = 0 ;

    for(i=n-1 ; i>=0 ; i--)
    {
        dp[i] = n+100 ;
        for(j=0 ; j<l ; j++)
        {
            if( dp[ Next[j][i]+1 ]+1 < dp[i] )
            {
                dp[i] = dp[ Next[j][i] + 1 ] + 1 ;
                ch[i] = j ;
            }
        }
    /*    printf("%d--->%c\n",i,ch[i]+'a') ;
        for(j=0 ; j<l; j++) printf("%d:%d ",j,Next[j][i]) ;
        printf("\n") ; */
    }

//    DBG ;

    int cur = 0 , len = 0 ;

    while( cur < n )
    {
  //      printf("%d\n",cur) ;
        ans[ len++ ] = ch[cur] + 'a' ;
        cur = Next[ ch[cur] ][ cur ] + 1 ;
    }

    ans[len] = '\0' ;

    printf("%s\n",ans) ;

    return 0 ;
}

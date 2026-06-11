#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007
#define IN freopen("hard1.txt","r",stdin)
#define OUT freopen("hard1.txt","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG pf("Hi\n")
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define off 1000005

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<i64, i64> pii;

#define INF 2000000000000000000LL
#define alpha 26

#define maxn 300005
#define LOG 18

int main()
{
    i64 n ;
    scanf("%lld",&n) ;

    int b = 0 ;

    for(int i=1 ; ; i++)
    {
        if( (1LL<<i) <= n ) b = i ;
        else break ;
    }

    vector <int> ans ;

    for(int i=1 ; i<=b ; i++)
    {
        ans.pb(i) ;
    }
    for(int i=1 ; i<=b ; i++) ans.pb(50+i) ;

    for(int i=1 , j=b ; i<=b ; i++,j--)
    {
        if( ((1LL<<(i-1))&n) ) ans.pb(50+j) ;
        ans.pb(i) ;
    }
    ans.pb(100) ; ans.pb(100) ;

    printf("%d\n",(int)ans.size()) ;
    for(int i=0 ; i<ans.size(); i++) printf("%d ",ans[i]) ;
    printf("\n") ;

    return 0 ;
}

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

#define maxn 200005
#define mod 998244353LL
#define lim 1000000000
#define INF 4500000000000000000LL
#define Max(x,y,z) max(max(x,y),z)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

char s[maxn] ;
int cnt[35] ;

int main()
{
    scanf("%s",s) ;

    int n = strlen(s) ;

    for(int i=0 ; i<n ; i++) cnt[ s[i]-'a' ]++ ;

    i64 ans = (1LL*(n-1)*n)/2 ;

    for(int i=0 ; i<26 ; i++)
    {
        ans -= ( 1LL*(cnt[i]-1)*cnt[i] )/2 ;
    }

    printf("%lld\n",ans+1) ;

    return 0 ;
}

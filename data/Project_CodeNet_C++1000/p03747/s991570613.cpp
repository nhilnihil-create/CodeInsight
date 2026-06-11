#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>/
// #include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007LL
#define IN freopen("nocross.in","r",stdin)
#define OUT freopen("nocross.out","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG printf("Hi\n")
#define INF 2000000000000000000LL
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define off 2
#define SZ(z) ((int)z.size())

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)


// using namespace __gnu_pbds;
using namespace std ;

// typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define maxn 300005

i64 ans[maxn] ;
i64 pos[maxn] , type[maxn] ;
i64 nextPos[maxn] ;

int main()
{
    i64 n , L , T ;

    scanf("%lld %lld %lld",&n,&L,&T) ;

    i64 cl = 0 , anticl = 0 ;

    for(int i=1 ; i<=n ; i++)
    {
        scanf("%lld %lld",&pos[i],&type[i]) ;
        if(type[i]==1) cl++ ;
        else anticl++ ;

        if( type[i] == 1 ) nextPos[i] = (pos[i]+T)%L ;
        else nextPos[i] = ((pos[i]-T)%L + L)%L ;
    }

    sort( nextPos+1 , nextPos+n+1 ) ;

    if( type[1] == 1 )
    {
        i64 collision = 0 ;
        collision = 2LL*(T/L)*anticl ;

        i64 p = (T+pos[1])%L ;

        for(int i=2 ; i<=n ; i++)
        {
            if(type[i]==1) continue ;

            if( ( pos[i]-pos[1] ) <= 2*(T%L) )
            {
                collision++ ;
                if( pos[1]+L-pos[i] <= (2*(T%L) - 2*( pos[i]-pos[1] )) ) collision++ ;
            }
        }

        collision %= n ;
        int idx = collision+1 ;

        int start = 1 ;

        for(int i=1 ; i<=n ; i++)
        {
            if( nextPos[i] == p  ) start = i ;
        }
        for(int i=start , j=1 ; j<=n ;  j++ )
        {
            ans[idx] = nextPos[i] ;

            idx++ ; if(idx>n) idx -= n ;
            i++ ; if(i>n) i -= n ;
        }
   //     return 0 ;
    }
    else{
        i64 collision = 0 ;
        collision = 2LL*(T/L)*cl ;

        i64 p = ( (pos[1]-T)%L + L )%L ;

        for(int i=n ; i>1 ; i--)
        {
            if(type[i]==2) continue ;

            if( (pos[1] + L-pos[i] ) <= 2*(T%L) )
            {
                collision++ ;
                if( (pos[i]-pos[1]) <= (2*(T%L) - 2*(pos[1] + L-pos[i] )) ) collision++ ;
            }
        }
        collision %= n ;

        int idx = 1 ;

        if(collision > 0) idx = n-collision+1 ;

        int start ;

        for(int i=n ; i>=1 ; i--)
        {
            if( nextPos[i] == p ) start = i ;
        }

        for(int j=1 , i= start ; j<=n ; j++)
        {
            ans[idx] = nextPos[i] ;
            i++ ; idx++ ;
            if(i > n) i -= n ;
            if(idx > n) idx -= n ;
        }
    }

    for(int i=1 ; i<=n ; i++)
    {
        printf("%lld\n",ans[i]) ;
     //   if(i==n) printf("\n") ;
     //   else printf(" ") ;
    }

    return 0 ;
}

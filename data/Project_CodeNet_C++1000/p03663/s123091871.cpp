#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define inf (1<<30)-1
#define INF (1LL<<62)-1
#define MOD 1000000007LL
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define PI acos(-1)
#define MEM(x,y) memset(x,y,sizeof (x))
#define debug cout<<"A"<<'\n'
#define REP(i,a,b) for (int i=(a); i<=(b); i++)
#define PER(i,a,b) for (int i=(a); i>=(b); i--)
#define REPL(i,a,b) for (LL i=(a); i<=(b); i++)
#define PERL(i,a,b) for (LL i=(a); i>=(b); i--)
#define print(x) cout<<x<<'\n'
#define itrALL(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define UNIQUE(X) X.erase( unique( X.begin(), X.end() ), X.end() )


typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int>PII;
typedef pair<LL,LL>PLL;
typedef vector<int> VI;
typedef vector<LL> VL;


// Order Statistic Tree

/* Special functions:

        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

typedef tree<
PII,
null_type,
less<PII>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

template <class T> inline T bigmod(T p,T e,T M)
{
    T ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}

template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
template <class T, class X> inline bool getbit(T a, X i) { T t=1; return ((a&(t<<i))>0);}
template <class T, class X> inline T setbit(T a, X i) { T t=1;return (a|(t<<i)); }
template <class T, class X> inline T resetbit(T a, X i) { T t=1;return (a&(~(t<<i)));}

/*end of header*/

LL ask(LL n)
{
    printf("? %lld\n",n);
    fflush(stdout);
    string s;
    cin>>s;
    if(s[0]=='Y')return 1;
    else return 0;
}

int main()
{
    //freopen("input_file_name.in","r",stdin);
    //freopen("output_file_name.out","w",stdout);
    LL p=-1;
    REPL(i,1,12)
    {
        if(ask(bigmod(10LL,i,INF)))continue;
        p=i-1;
        break;
    }
    if(p==-1)
    {
        LL ans;
        REPL(i,0,10)
        if(ask(bigmod(10LL,i,MOD)+1)){ans=(bigmod(10LL,i,MOD));break;}
        printf("! %lld\n",ans);
        return 0;
    }
    LL best;
    if(p==0)
    {
        best=10;
    }
    else
    {
        LL lo=bigmod(10LL,p-1,INF),hi=bigmod(10LL,p,INF)-1,mid;
        while(hi>=lo)
        {
            LL mid=(hi+lo)/2;
            if(ask(mid))
            {
                best=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        best*=100LL;
    }
    while(!ask(best))best+=10;
    best/=10;
    printf("! %lld\n",best);
    return 0;
}


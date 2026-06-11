/*!enjoy karo yaar!*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

#include<bits/stdc++.h>
using namespace std;

#define     int             long long int
#define     fast()          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)          (x).begin(),(x).end()
#define     rz(x)           resize(x)
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     sz(x)           ((int)(x.size()))
#define     pb              push_back
#define     pf              push_front
#define     pob             pop_back
#define     pof             pop_front
#define     ins             insert
#define     vi              vector<int>
#define     pii             pair<int,int>
#define     mii             map<int,int>
#define     F               first
#define     S               second
#define     makep           make_pair
#define     maket           make_tuple
#define     remax(a,b)      a=max(a,b)
#define     remin(a,b)      a=min(a,b)
#define     bitcount(x)     __builtin_popcountll(x)
#define     iceil(n,x)      (((n)+(x)-1)/(x))
#define     gcd(a,b)        (__gcd((a),(b)))
#define     lcm(a,b)        (((a)*(b))/gcd((a),(b)))
#define     dbug(x)         cout<<#x<<": "<<(x)<<"\n"
#define     flush           fflush(stdout)
#define     show(x)         for(auto zz:x)cout<<zz<<" ";cout<<"\n";
#define     show2(x)        for(auto zz:x)cout<<zz.F<<" "<<zz.S<<"\n";

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ld pi=acos(-1);
const ll inf=1e18,M=1e9+7;
const int N=1;

void solve()
{
    int n,x;
    cin>>n>>x;

    int m=2*n-1;

    if(x==1 || x==m)
    {
        cout<<"No";
        return;
    }

    cout<<"Yes\n";

    vi v(m+1);

    v[m/2]=1;
    v[m/2+1]=x;
    v[m/2+2]=m;

    int cur=1;
    for(int i=1;i<m/2;++i)
    {
        if(cur!=1 && cur!=x && cur!=m)
            v[i]=cur;
        else
            --i;
        ++cur;
    }

    for(int i=m/2+3;i<=m;++i)
    {
        if(cur!=1 && cur!=x && cur!=m)
            v[i]=cur;
        else
            --i;
        ++cur;
    }

    for(int i=1;i<=m;++i)
        cout<<v[i]<<"\n";
}

int32_t main()
{
    fast();

    int t=1;
    //cin>>t;
    for(int z=1;z<=t;++z)
    {
        solve();
        //cout<<"\n";
    }

    return 0;
}



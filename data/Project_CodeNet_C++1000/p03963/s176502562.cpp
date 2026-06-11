#include<bits/stdc++.h>
using namespace std;
// -----------------<fast IO>------------------
#define IOS             ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FLSH             fflush(stdout)
#define fileIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);
#define PRECISION(x)     cout << fixed << setprecision(x);
//#define endl             "\n"
// -----------------<Container manipulation / traversal macros>------------------
//#define mp                 make_pair
#define pb                 push_back
#define ff                 first
#define ss                 second
#define sz(x)             ((int)((x).size()))
#define all(x)             (x).begin(),(x).end()
#define rep(i,n)         for(ll (i)=0;(i)<(n);(i)++)
#define forn(i,a,b)     for(ll (i)=(a);(i)<=(b);(i)++)
#define fill(l,a)        memset((l) , (a) , sizeof(l))
// -----------------<Some common useful functions>------------------
#define maX(a,b)        ( (a) > (b) ? (a) : (b))
#define miN(a,b)        ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)   ( (n >> b) & 1)
#define INDEX(arr,i)      ( lower_bound(all(arr),i)-arr.begin())
#define in(b,a)         ( (b).find(a) != (b).end())
// -----------------<TypeDef Start>------------------
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector< std::vector<ll> > matrix;
typedef map<ll,ll> mii;
typedef vector<pii> vpii;
// -----------------<Constants>------------------
const int MAXN = 1000005;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI=acos(-1);
 
const int INF=1e9;
 
int MOD = 1000000007;
const int FMOD = 998244353;
const double eps = 1e-9;
ll gcd(ll a,ll b)
{
    if(a==0)
    return(b);
    return(gcd(b%a,a));
}
ll lcm(ll a,ll b)
{
    return(a/gcd(a,b)*b);
}
/*ll power(ll a,ll b,ll p)
{
    ll res=1;
    a%=p;
    while(b>0)
    {
        if(b&1)
        res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return(res);
}*/
/*ll modInverse(ll a, ll m)
{
    ll g = gcd(a, m);
    return(power(a,m-2,m));
}*/
/*ll b_search(ll arr[],ll n,ll s)
{
    ll l=0,r=n-1;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;
        if(arr[mid]==s)
        return(mid);
        if(arr[mid]<s)
        l=mid+1;
        else
        r=mid-1;
    }
    return(-1);
}*/
/*bool isprime(ll x)
{
    if(x==1)
        return(false);
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
            return(false);
    }
    return(true);
}*/
/*vector<ll> v[100005];
bool vis[100005]={false};
long combi(int n,int k)
{
    long ans=1;
    k=k>n-k?n-k:k;
    int j=1;
    for(;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}*/
/*struct cmp{
    bool operator()(const pair<ll,ll>&a,const pair<ll,ll>&b)
    const{
        int lena=a.second-a.first+1;
        int lenb=b.second-b.first+1;
        if(lena==lenb) return a.first<b.first;
        return lena>lenb;
    }
};*/
void solve()
{
    ll n,k;
    cin>>n>>k;
    ll ans=k;
    for(ll i=0;i<n-1;i++)
        ans*=(k-1);
    cout<<ans<<endl;
}
 
 
int main()
{
    IOS
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return(0);
}
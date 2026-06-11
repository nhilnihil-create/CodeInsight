
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
#define int long long int
typedef complex<long double> cd;
const long double pi=acos(-1);
typedef double db;
typedef long double ldb;
typedef pair <int,int> pii;
typedef pair <db,db> pdd;
typedef vector<int> vi;
typedef vector<vector<int> > matrix;

#define m1 make_pair
#define pb push_back
#define flush fflush(stdout)
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define reset(x,v) memset(x,v,sizeof(x))

#define fi first
#define se second
#define endl "\n"
#define debug(x) (cerr << #x << ": " << x << "\n")
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>

inline int gcd(int a,int b){if(a==0) return b;return gcd(b%a,a);}
inline int power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p%m*p%m)%m;if(n%2) return (p%m*a%m)%m;else return p;}
const double EPS = 1e-9;
const ll MOD =998244353;
const ll hell=1000000007;
const int INF = 1e18;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
template<typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 rng(seed);

double startTime;
double getCurrentTime() {
    return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

const int N=200005;

int f[N+1],inf[N+1];

int C(int n,int r)
{
    if(r>n)
        return 0;
    int ans=(f[n]*inf[r])%hell;
    return (ans*inf[n-r])%hell;
}
int ways(int x1,int y1,int x2,int y2)
{
    return C(x2-x1+y2-y1,x2-x1);
}

void preprocess()
{
    f[0]=1;
    for(int i=1;i<=N;i++)
        f[i]=(f[i-1]*i)%hell;
    inf[N]=power(f[N],hell-2,hell);
    for(int i=N-1;i>=0;i--)
        inf[i]=(inf[i+1]*(i+1))%hell;
}

void solve()
{
   
    int n,m;
    cin>>n>>m;
    int a,b;
    cin>>a>>b;
    a=n-a+1;
    int pre=0;
    int ans=ways(1,1,n,m);
    for(int i=1;i<=b;i++)
    {
        int Z=ways(1,1,a,i);
        Z=(Z-pre+hell)%hell;
        ans=(ans-(Z*ways(a,i,n,m))%hell+hell)%hell;
        pre=(pre+Z)%hell;
    }
    cout<<ans<<endl;
}


int32_t main(){
    
    IOS;
    preprocess();
    int t;
    t=1;
    // cin>>t;
    while(t--)
    {
        
        solve();
    }
    return 0;
}



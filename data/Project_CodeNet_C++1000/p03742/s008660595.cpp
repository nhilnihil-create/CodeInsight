#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <algorithm>

#define scd(a) scanf("%d",&a)
#define scdd(a,b) scanf("%d%d",&a,&b)
#define scddd(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep1(i,n) for(int i=1; i<=(n); i++)
#define mst(x,a) memset(x, a, sizeof(x))
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define ALL(x) x.begin(),x.end()
#ifdef LOCAL
    #define dbg(a) cout << #a": " << a << endl;
#else
    #define dbg(a)
#endif // LOCAL

using namespace std;
typedef long long ll;
typedef unsigned int uin;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const double dinf = inf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<double,double> pdd;

ll qpow(ll a, ll b, ll mod){
    ll ret = 1;
    for(;b; b>>=1){
        if(b&1) ret = ret*a%mod;
        a = a*a%mod;
    }
    return ret;
}

const int N = 1e5 + 10;
const int M = 1e4 + 10;
const int mod = 998244353;
const double eps = 1e-6;



int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout.tie(0);

    ll x,y;
    cin>>x>>y;
    if(abs(x-y)<=1) printf("Brown\n");
    else printf("Alice\n");

    return 0;
}

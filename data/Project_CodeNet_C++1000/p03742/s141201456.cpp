#include <bits/stdc++.h>
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
#define ls rt<<1
#define rs rt<<1|1
#define lson rt<<1, l, M
#define rson rt<<1|1, M+1, r
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
typedef pair<ll,ll> PLL;
typedef pair<ull,ull> puu;
typedef pair<double,double> pdd;

const int N = 2e5 + 10;
const int M = 18 + 10;
const int mod = 998244353;
const double eps = 1e-10;
const double PI = acos(-1.0);



void work(){
    ll x,y;
    while(~scanf("%lld%lld",&x,&y)){
        if(y>x) swap(x,y);
        if(x-y<2) printf("Brown\n");
        else printf("Alice\n");
    }
}

int main()
{
#ifdef LOCAL
    freopen("inb.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif // LOCAL
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    //int T;
    //scd(T);
    //while(T--)
        work();

    return 0;
}

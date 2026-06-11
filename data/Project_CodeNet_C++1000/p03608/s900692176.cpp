// --------------------<optimizations>--------------------
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)\
#pragma GCC optimize("unroll-loops")

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair<ll,ll>
#define vpii vector<pair<ll,ll> >
#define F first
#define S second
#define ld long double
#define built __builtin_popcountll
#define mst(a,i) memset(a,i,sizeof(a))
#define all(x) x.begin(),x.end()
#define itit(it,a) for(auto it=(a).begin(); it!=(a).end(); it++)
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define repr(i,a,b) for(ll i=a; i>b; i--)
#define reprr(i,a,b) for(ll i=a; i>=b; i--)
#define pi 3.14159265358979323846264338327950288419716939937510582097494459230
ll max3(ll x,ll y,ll z) {return max(max(x,y),z);}
ll min3(ll x,ll y,ll z) {return min(min(x,y),z);}
const ll N=1e5+10,M=2e5+10,M2=1e6+10,mod=1e9+7,inf=1e17+10;
const int INF=1e9+7;
void add(int& a, int b) {a+=b;if(a>=mod){a-=mod;}}


int X[] = {0, 1, 0, -1};
int Y[] = {-1, 0, 1, 0};
//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
ll power(ll x,ll n){ll result=1;while(n>0){if(n%2==1)result=(result*x)%mod; x=((x%mod)*(x%mod))%mod;n=n/2;}return result;}

const int Z=205;
int n,m,r;
int d[Z];
int lol[Z][Z];
int res;
bool used[Z];

void floyd_warshall(){
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                lol[j][k]=min(lol[j][k],lol[j][i]+lol[i][k]);
}

void dfs(int c, int last, int dist){
    if(c==r+1){
        res=min(res,dist);
        return;
    }
    for(int i=1; i<=r; i++){
        if(!used[i]){
            used[i]=true;
            if(last==-1) dfs(c+1,i,0ll);
            else dfs(c+1,i,dist+lol[d[i]][d[last]]);
            used[i]=false;
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> r;
    rep(i,1,r+1) cin >> d[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i!=j) lol[i][j]=inf;

    rep(i,0,m){
        int a,b,c;
        cin >> a >> b >> c;
        lol[a][b]=c;
        lol[b][a]=c;
    }
    floyd_warshall();
    res=inf;
    dfs(1,-1,0);
    cout << res;
    return 0;
}
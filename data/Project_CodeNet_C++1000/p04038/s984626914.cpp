//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

#define arr (int)(1e7+10)

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=res*a%md;
        }
        n/=2;
        a=a*a%md;
    }
    return res;
}

void inc(int& a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
}

int f[arr];
int rf[arr];

int C(int n,int k)
{
    return f[n]*rf[k]%md*rf[n-k]%md;
}

int H(int n,int m)
{
    return C(n+m,n);
}

int dp[ar][ar];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    f[0]=1;
    for (int i=1;i<arr;i++){
        f[i]=f[i-1]*i%md;
    }
    rf[arr-1]=bpow(f[arr-1],md-2);
    for (int i=arr-2;i>=0;i--){
        rf[i]=rf[i+1]*(i+1)%md;
    }

    int n,k;
    cin>>n>>k;
    if (k==1){
        cout<<1<<"\n";
        return 0;
    }
    dp[0][0]=1;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            if (i!=0){
                inc(dp[i][j],dp[i-1][j]);
            }
            if (i<j){
                inc(dp[i][j],dp[i][j-1]*H(k-2,(j-i-1)*(k-1)+i*(k))%md);
            }
//            cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
        }
    }
    int ans=dp[n][n]*f[n]%md;
    cout<<ans<<"\n";
}

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
///#define int long long

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

#define ar (int)(5000+10)

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=1ll*res*a%md;
        }
        n/=2;
        a=1ll*a*a%md;
    }
    return res;
}

int inv(int a)
{
    return bpow(a,md-2);
}

int dp[ar][ar];

void inc(int& a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif



    int n;
    cin>>n;
    string s;
    cin>>s;
    int k=len(s);

    dp[0][0]=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            inc(dp[i+1][j+1],1ll*dp[i][j]*2%md);
            inc(dp[i+1][max(0,j-1)],dp[i][j]);
        }
    }
    int ans=1ll*dp[n][k]*inv(bpow(2,k))%md;
    cout<<ans<<"\n";
}

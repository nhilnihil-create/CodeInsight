#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,int> pii;
typedef priority_queue< int, vector< int >, greater< int > >  minHeap;

#define ones(x) __builtin_popcount(x)
#define onesl(x) __builtin_popcountl(x)
#define onesll(x) __builtin_popcountll(x)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
#define scn3(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scn2ll(n,m) scanf("%lld%lld",&n,&m)
#define atoz(v) v.begin(),v.end()
#define ratoz(v) v.rbegin(),v.rend()
#define Fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define ten(n) (int)1e##n
#define tenll(n) (lli)1e##n
#define mod 1000000007
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N = N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}


inline int addmod(int x ,int y){return (x%mod + y%mod)%mod;}
inline int submod(int x ,int y){return (x%mod - y%mod + mod)%mod;}
inline int mulmod(int x ,int y){return (x%mod *1LL* y%mod)%mod;}
inline int nextSubMask(int i , int mask) {return (i-1)&mask;} /// returns next smallest submask

void we_r_done(){cout<<"NO"; exit(0);}

void debug(bool ok , string mssg)
{
    if(ok)return;
    cout<<mssg;
    exit(0);
}

lli dp[66][55];

lli nCr(int n, int r)
{
 if(n==r) return dp[n][r] = 1;
 if(r==0) return dp[n][r] = 1;
 if(r==1) return dp[n][r] = n;
 if(dp[n][r]) return dp[n][r];
 return dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}

int main()
{
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);

    //FastIO;

    cout<<setprecision(7)<<fixed;



    int n, A , B;
    cin>>n>>A>>B;
    lli a[n];
    map<lli,int>cnt;
    long double ans = 0;
    lli tot = 0;

    for(int i=0; i<n; i++){
        cin>>a[i];
        cnt[a[i]]++;
    }

    sort(a,a+n);

    map<lli,int>took;
    int AA = A;
    lli l = -1;
    for(int i=n-1; i>=0 && A ; i-- , A--){

        tot += a[i];
        took[a[i]]++;
        l = a[i];
    }

    ans = tot/(double)AA;

    lli ways = nCr(cnt[l] , took[l]);

    if(ans == l) for(int i=took[l]+1; B>=(AA+i-took[l]) &&  i<=cnt[l]; i++) ways += nCr(cnt[l] , i);



    cout<<ans<<endl<<ways;

    return 0;

}

///sin and cos expect input in radians not degrees. so use , sin(degrees * pi / 180)
///using bs = bitset<MX>; // how many distinct number can be form?

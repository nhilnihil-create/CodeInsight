#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define pll pair<lli, lli>
#define vi  vector<int>
#define vii vector<pair<int,int>>
#define vll vector<lli>
#define pb  push_back
#define mpr  make_pair
#define ss  second
#define ff  first
#define INF 1000000001
#define inf1 1000000000000000001
#define pie 3.14159265358979323846264338327950L
#define all(x) x.begin(),x.end()
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define testcase() int tc;cin>>tc;while(tc--)
#define clean(x) memset(x,0,sizeof(x))
const lli maxn = 1e7+9;
const lli mod= 1000000007;
vector<lli> catlan(int n) {
    vector<lli> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i ++) {
        for (int j = 0; j < i; ++ j) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp;
}
lli digit(lli n){int res=(int)log10(n)+1;return res;}
lli lcm(lli a,lli b){lli ans=(a*b)/(__gcd(a,b));return ans;}
lli b_ex(lli n,lli a){lli res=1;while(n){if(n%2==1)res*=a;n>>=1;a=a*a;}return res;}
lli ncr(lli n,lli k){lli ans=1;if(k>n-k)k=n-k;for(lli i=1;i<=k;i++){ans*=(n-i+1),ans=ans/i;}return ans;}
lli power(lli a , lli n){lli ans = 1;while(n){if(n % 2)ans = (ans * a) % mod;n /= 2;a = (a * a) % mod;}return ans;}
lli set_bits(lli n)
{
    int c=0;
    if(n==0)return 0;
    while(n)
    {
        if((n&1)==1)
        {
           cout<<c<<" ";
        }
        c++;
        n=n>>1;
    }
    return c;
}
///=================== ALWAYS CHECK 1 or 0 base case=================================================================================///
///------------------ALWAYS lli-----TEMP TSF99--------------------------------------------------------------------------------------///

void solve()
{
    pair<lli,lli>p[100000];
    lli n,k;cin>>n>>k;
    lli sum=0;
    for(int i=0;i<n;i++)
    {
        lli a,b;cin>>a>>b;
        p[i].ff=a,p[i].ss=b;
    }
    sort(p,p+n);
    for(int i=0;i<n;i++)
    {
        sum+=p[i].ss;
        if(sum>=k)
        {
            cout<<p[i].ff<<endl;return;
        }
    }

}
int main()
{
    solve();
}

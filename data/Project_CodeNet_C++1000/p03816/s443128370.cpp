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
#define mod 1000000007
#define pie 3.14159265358979323846264338327950L
#define all(x) x.begin(),x.end()
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define testcase() int tc;cin>>tc;while(tc--)
#define clean(x) memset(x,0,sizeof(x))
const lli maxn = 1e5+9;
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
lli lcm(lli a,lli b)
{
    lli ans=(a*b)/(__gcd(a,b));
    return ans;
}
///------------------ALWAYS lli-----TEMP TSF99--------------------------------------------------------------------------------------///
map<int,int>m;
void solve()
{
    lli n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        m[a]++;
    }
    priority_queue<int>q;
    int c=0;
    for(pii i:m)
    {
        if(i.ss>1)q.push(-i.ss);
        else if(i.ss==1)c++;
    }
    while(!q.empty())
    {
        int x=-1*q.top();
        int y;
        q.pop();
        if(!q.empty())
        {
            y=-1*q.top();
            q.pop();
        }
        else
        {
            if(x%2==1)c++;
            break;
        }
        int z=min(x-1,y-1);
        x-=z,y-=z;
        if(x==1)c++;
        if(y==1)c++;
        if(x>1)q.push(-x);
        if(y>1)q.push(-y);
    }
    cout<<c<<endl;

}
int main()
{
    FAST;
    //int tc=1;cin>>tc;while(tc--)solve();
    solve();
}


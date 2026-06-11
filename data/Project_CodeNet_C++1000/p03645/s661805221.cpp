#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define pll pair<lli,lli>
#define vi  vector<int>
#define vii vector<pair<int,int>>
#define vll vector<lli>
#define pb  push_back
#define mp  make_pair
#define ss  second
#define ff  first
#define all(x) x.begin(),x.end()
const lli mod = 1e9+7;
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
lli p2(lli n){lli ans=0;while(n>=1){n=n/2;ans++;}return ans;}
lli b_ex(lli n,lli a){lli res=1;while(n){if(n%2==1)res*=a;n>>=1;a=a*a;}return res;}
lli ncr(lli n,lli k){lli ans=1;if(k>n-k)k=n-k;for(lli i=1;i<=k;i++){ans*=(n-i+1),ans=ans/i;}return ans;}
lli add(lli a,lli b){return(a+b)%mod;}
lli mul(lli a,lli b){return (a*b)%mod;}
lli power(lli a , lli n){lli ans = 1;while(n){if(n % 2)ans = (ans * a) % mod;n /= 2;a = (a * a) % mod;}return ans;}
lli lcm(lli a,lli b)
{
    lli ans=(a*b)/(__gcd(a,b));
    return ans;
}
int n,m;
vi adj[200001];
int vis[200001];
bool f;
void dfs(int curr,int c=0)
{
    vis[curr]=1;
    if(curr==n){f=true;return;}
    if(c==2)return;
    for(int i:adj[curr])
    {
        if(vis[i]==0)dfs(i,c+1);
    }

}
int main()
{
    cin>>n>>m;
    while(m--)
    {
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    if(f)cout<<"POSSIBLE\n";
    else cout<<"IMPOSSIBLE\n";
}




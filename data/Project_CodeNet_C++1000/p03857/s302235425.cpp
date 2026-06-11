 /***     
 * When I wrote this
 * only God & I understood
 * what I was doing
 * Now, God only knows 
 /***/ 
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include <iomanip>
#include<map>
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<=n;i++)/*i为循环变量，a为初始值，n为界限值，递增*/
#define per(i,a,n) for (int i=a;i>=n;i--)/*i为循环变量， a为初始值，n为界限值，递减*/
const int mod = 1e9+7;
using namespace std;
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
//fixed<< setprecision(2)
const int MAXN=2e6+10;
typedef pair<int,int>P;
map<P,int>ans;
ll fa[MAXN],ma[MAXN];
void init(int n)
{
    rep(i,0,n){fa[i]=i;ma[i]=i;}
}
int Find(ll *fa,ll x)
{
    if(fa[x]==x)return fa[x];
    return fa[x]=Find(fa,fa[x]);
}
void unin(ll x,ll y,ll *fa)
{
    x=Find(fa,x);
    y=Find(fa,y);
    fa[x]=y;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    ll n,k,l;
    while(cin>>n>>k>>l)
    {
       init(n);
       ans.clear();
       for(int i=0;i<k;i++)
       {
           ll x,y;
           cin>>x>>y;
           unin(x,y,ma);
       }
       for(int i=0;i<l;i++)
       {
           ll x,y;
           cin>>x>>y;
           unin(x,y,fa);
       }
       for(int i=1;i<=n;i++)
       {
           ans[make_pair(Find(ma,i),Find(fa,i))]++;
           
       }
       rep(i,1,n)
       {
           cout<<ans[make_pair(Find(ma,i),Find(fa,i))]<<" ";
       }
       cout<<'\n';
    }
}
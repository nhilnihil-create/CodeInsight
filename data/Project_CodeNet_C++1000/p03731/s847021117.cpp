#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF (int)1e9+7
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define N 100005
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795



ll binPowM(ll a,ll b, ll m)
{ 
  ll ans=1;
  while(b>0)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }
return ans%m;
}
ll f(ll x,ll y,ll a)
{
  return (a&x)*(a&y);
}

int main()
{  
  
ll n,t;
cin>>n>>t;
vector<ll>a(n+1);
for(int i=1;i<=n;i++)
{
  cin>>a[i];
}
ll cur=t,dif=0;

for(int i=2;i<=n;i++)
{
     dif+=max(a[i]-cur,(ll)0);
     cur=t+a[i];
}

cout<<t+a[n]-dif<<"\n";


  return 0;

}




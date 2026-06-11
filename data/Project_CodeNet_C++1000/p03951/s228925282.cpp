#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD (int)1e9+7
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>b;--i)
#define vi vector<int>
#define vl vector<ll>
#define ld long double
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(),x.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);



ll powM(ll a,ll b,ll m )
{ 
  a%=m;
  ll ans=1;
  while(b>0)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }

return ans;
}

ll pow(ll a,ll b)
{ 
  
  ll ans=1;
  while(b)
  {
    if(b&1)ans=ans*a;
    a=a*a;
    b>>=1;
  }

return ans;
}

ll dp[105][1005];
char ch[105][1005];


int main()
{fast


ll n;cin>>n;

string s,t;
cin>>s>>t;

ll ans=0;


for(ll i=0;i<n;i++)
{
string t1=t.substr(0,i+1);
string s1=s.substr(n-i-1,i+1);
if(s1==t1)
{
  ans=max(ans,i+1);
}
}


cout<<2*n-ans<<"\n";


 return 0;

}

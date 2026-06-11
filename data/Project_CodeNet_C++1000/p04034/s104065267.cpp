#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> 
//using boost::multiprecision::cpp_int;
using namespace std;
#define ll long long int
#define F first
#define S second
//#define endl "\n"
//#define nl cout<<endl;
#define pb push_back
#define ull unsigned long long 
#define f(i,a,b) for(ll i=a;i<b;i++)
#define Knucklehead ios_base::sync_with_stdio(false);cin.tie(NULL);
//#define mod 100000007
#define mat vector<vector<ll>>
mat cn(ll n, ll m){return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1,char &s2){return s1 > s2;} 
bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b) 
{ 
    if(a.first < b.first )
        return true;
    if( a.first==b.first && a.S != b.second )
       return true;
    return false;
}
bool cmp(int n, pair<int, int> const& p)
{
    return (p.first < n);
}
//me
ll const mod = 1e9+7;//998244353;
ll const inf = 1e18;
ll const maxn = 2e5+1;

int stoint(string s)
{
     int n = s.size();
     int num = 0;
     f(i,0,n){
          num = num*10+ (int)(s[i]-'0');

     }
     return num;
}

ll fastpow(ll a, ll b)
{
     ll res = 1;
     while(b){
          if(b&1) res *= a;
          a*=a;
          b/=2;
     }
     return res;
}

void solve()
{      

     ll n,m; cin >> n >> m;

     ll cnt[n],red[n];
     fill(cnt, cnt+n,1);
     fill(red, red+n, 0);
     red[0]=1;

     f(i,0,m){
          ll x,y; cin >> x >> y;
          x--,y--;
          if(red[x] && cnt[x])
               red[y]=1;

          if(cnt[x])
               cnt[x]--, cnt[y]++;
          if(cnt[x]==0)
               red[x]=0;
     }
     ll ans = 0;
     f(i,0,n)
          ans+=red[i];
     cout << ans << endl;
}    

int main() {
Knucklehead 
//*
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
/**/ 
          
          ll t;
          /**/t=1;
          /*/cin>>t;/**/
          f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
          }
 
 
    return 0;
}
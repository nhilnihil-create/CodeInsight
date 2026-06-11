
#include <bits/stdc++.h>
#include <ext/rope>
#define VALHALLA cin.tie(0);ios_base::sync_with_stdio(false);cout<<fixed<<setprecision(13);
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define debug(x) std::cerr << #x << ": " << (x) << '\n';
#define sz(x) (int)x.size()
#define fast(map_name) map_name.reserve(1024);map_name.max_load_factor(0.25);
using namespace std;
using namespace __gnu_cxx;
typedef long long int ll;
typedef pair<int,int> ii;
typedef complex<double> point;
const double epsilon=1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod=1e9+7;
/* VARIABLE DECLARATION START */
int arr[int(1e5+1)];
int dp[int(1e5+1)][5];
string s;
/*  FUCNTION TEMPLATE STARTS  HERE */

double dot(point a,point b){ return (conj(a)*b).real() ; }
double cross(point a,point b){ return (conj(a)*b).imag() ; }
double dist(point a, point b){ return abs(a-b); }
struct neal {
static uint64_t splitmix64(uint64_t x)
 {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}
size_t operator()(uint64_t x) const
 {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
}
};
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return (size_t) x.first * 37U + (size_t) x.second;
  }
};
bool isprime(ll n) {
    if (n == 2 || n == 3) return true;
    if (n < 2 || n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 6; (i - 1) * (i - 1) <= n; i += 6) {
        if (n % (i - 1) == 0 || n % (i + 1) == 0) {
            return false;
        }
    }
    return true;
}
inline ll exp(ll a, ll b, ll mod) {
    ll n = 1;
    ll p = a;
    while (b > 0) {
        if (b % 2 == 1) {
            n *= p;
            n %= mod;
        }
        p *= p;
        p %= mod;
        b /= 2;
    }
    return n;
}

inline bool comp(double a,double b)
{
  return (fabs(a-b)<epsilon);
}
ll gcd(ll u, ll v) {
  ll r;
  while (0 != v) {
    r = u % v; u = v; v = r;
  }
  return u;
}
int solve(int index,int rock,int paper,int dec)
{
  if(index<0)
    return 0;
  if(dp[index][dec]!=-1)return dp[index][dec];
  int ans=0;
  if(rock>=paper+1)
  {
    if(s[index]=='p')
    {
      int val1=solve(index-1,rock,paper+1,1);
      int val2=-1+solve(index-1,rock+1,paper,0);
      if(val1>val2)
        return dp[index][1]=val1;
      else
        return dp[index][0]=val2;
    }
    else
    {
      int val1=1+solve(index-1,rock,paper+1,1);
      int val2=solve(index-1,rock+1,paper,0);
      if(val1>val2)
        return dp[index][1]=val1;
      else
        return dp[index][0]=val2;
    }
  }
  else
  {
    if(s[index]=='p')
    ans=-1+solve(index-1,rock+1,paper,0);
    else
    ans=solve(index-1,rock+1,paper,0);
    return dp[index][0]=ans;
  }
}


/*  FUCNTION TEMPLATE ENDS HERE */
int main()
{
   VALHALLA
  cin>>s;
  memset(dp,-1,sizeof(dp));
  cout<<max(solve(sz(s)-1,0,0,0),solve(sz(s)-1,0,0,1))<<endl;


}

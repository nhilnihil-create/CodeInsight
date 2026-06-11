#include<bits/stdc++.h>
#define sp  set< pair<ll,ll> >
#define vp vector< pair<ll,ll> >
#define spp set< pair<pair<ll,ll>,ll> >
#define maxe 100000000
#define MOD 1000000007
#define ll long long int
#define pb push_back
#define mp  make_pair
#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PI;
typedef vector<PI> VPI;
typedef map<int,int> MPII;
typedef set<int> SETI;
#define ps fixed<<setprecision(y)<<x;
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define ALL(cont) cont.begin(), cont.end()
#define RALL(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define FOREACH_FN(v, fn) for_each(ALL(v), myobject);

#define SORT(a) sort(a.begin(),a.end())
#define RSORT(a) sort(a.rbegin(),a.rend())
#define REV(a) reverse(a.begin(),a.end())
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MINIMUM(a)	*min_element(a.begin(), a.end())
#define MAXIMUM(a)	*max_element(a.begin(), a.end())

#define ld long double
#define bigint int64_t
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define hurry ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>
#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))
const int N =1e+5;
int main()
{
hurry;
ll n,l,i;
vector<string> v;
string s;
cin>>n>>l;
for(i=0;i<n;i++)
{
  cin>>s;
  v.pb(s);
}
SORT(v);
for(i=0;i<v.size();i++)
cout<<v[i];
}

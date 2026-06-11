#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
long long power(long long x, long long y, long long mood) {
	if (y == 0)
		return 1;
	long long ret = power(x, y >> 1, mood) % mood;
	if (y % 2 == 0)
		return (ret * ret) % mood;
	else
		return (x * (ret * ret % mood)) % mood;
}
const double Eps = (1e-9);
int dcmp(double x, double y) {
	return fabs(x - y) <= Eps ? 0 : x < y ? -1 : 1;
}
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_setpair;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pair<int, int> > vii;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef pair<int, int> pii;
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define sll set <ll>
#define spii set <pii>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1,v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1,v2,v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define el	'\n'
#define lp(i,n) for(int i = 0;i < int(n);i++)
#define lp1(i,n) for(int i = 1;i <= int(n);i++)
#define rlp(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rng(i,a,b) for(int i = int(a);i <= int(b);i++)
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define pob()    	pop_back()
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define bits(a) 	__builtin_popcountll(a)
#define fr first
#define sc second
#define pii pair<int, int>
#define sortva(v) sort(all(v))
#define sortvd(v) sort(v.rbegin(),v.rend())
#define sortaa(a,n) sort(a,a+n)
#define sortad(a,n) sort(a,a+n),reverse(a,a+n)
#define SS stringstream
#define ll long long
#define clr(x, y) memset(x, y, sizeof(x))
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(7), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
const long long key1 = (31);
const long long key2 = 59;
int dx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int dy[] = { 1, 0, -1, 0, -1, 1, 1, -1 };
int kx[] = { 2, 2, 1, -1, -2, -2, 1, -1 };
int ky[] = { 1, -1, 2, 2, 1, -1, -2, -2 };
int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
ll lcm(ll a, ll b) {
	return (a / gcd(a, b)) * b;
}
int setBit(int num, int idx, int val) {
	return val ? (num | (1 << idx)) : (num & (~(1 << idx)));
}
int getBit(int num, int idx) {
	return ((num >> idx) & 1) == 1;
}
int const N = 1e6+5 , mod = 1e9 + 7, oo = 1e9 + 10;
//-------------------------------------------------------------------------------------

int n;
ll arr[N],a,b;
bool okk(ll number,ll ases,ll total ){
return ((ases*a+(total-ases)*b)>=number);
}

ll bss(ll number,ll x,ll total){
ll lo=0,hi=total-x,med;
while(lo<hi){
	med=lo+(hi-lo)/2;
	if (okk(number,med,total))hi=med;
	else lo=med+1;
}
return lo;

}
bool ok(ll nofas){
ll x=0;
lp(i,n){
if (((nofas-x)*a+(x*b))<arr[i])return 0;
x+=bss(arr[i],x,nofas);
//x-=(arr[i]-	((nofas-x)*b)+a-1)/a;
}
return (x<=nofas);
}
ll bs(){
ll lo=1,hi=1e10,med;
while(lo<hi){
	med=lo+(hi-lo)/2;
	if (ok(med))hi=med;
	else lo=med+1;
}
return lo;
}
int main()
{
	cin>>n>>a>>b;
	lp(i,n)cin>>arr[i];
	sort(arr,arr+n);
	reverse(arr,arr+n);
	cout<<bs();
	return 0;
}

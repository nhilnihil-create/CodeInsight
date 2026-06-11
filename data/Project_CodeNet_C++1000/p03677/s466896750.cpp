#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define fu(a,b,c) for(int a=b;a<=(int)c;++a)
#define fd(a,b,c) for(int a=b;a>=(int)c;--a)
#define cu(a,b,c) for(int a=b;a<(int)c;++a)
#define cd(a,b,c) for(int a=(b)-1;a>=(int)c;--a)
#define gcd(a,b) __gcd(a,b) 
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define pf push_front
#define uint unsigned int
#define MOD 1000000007
#define MAXN 200005
#define MAXH 4
#define MAXM 100
#define INF 1LL << 60
#define ll long long
#define ull unsigned long long
#define RNG rng mt19937(time(NULL))
#define udist(a,b) uniform_int_distribution<uint32_t> distribution(a,b)
#define max3(a,b,c) max(a, max(b, c))
#define min3(a,b,c) min(a, min(b, c))
#define gmax(a,b) a = max(a, b)
#define gmin(a,b) a = min(a, b)
#define whatis(x) cerr << #x << " is " << x << endl;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.1415926535897932384626433
using namespace std;
const int N = 100005;
vector<int> nd[N];
int st[N];
int n,m;

inline int fdist(int x,int y){
	if(y >= x)return y - x;
	else return m - x + y - 1 + 1;
}

int main(){
	fast_io();
	cin >> n >> m;
	int a[n];
	cu(i,0,n)cin >> a[i];	
	ll tot = 0;
	ll ans = 0;
	int cnt = 0;
	cu(i,1,n){
		int x = a[i-1],y = a[i];
		tot += min(fdist(x,y),fdist(1,y) + 1);
		if(x > y){
			++cnt;
			++st[(x==m?1:x+1)];	
			nd[y].pb(x);
		}
		else{
			++st[(x==m?1:x+1)];	
			nd[y].pb(x);
		}
	}
	ans = tot;
	cnt -= nd[1].size();	
	for(int x: nd[1]){
		tot += fdist(x,1) - 1;
	}
	fu(i,2,m){
		tot-=cnt;
		gmin(ans, tot);
		cnt += st[i];
		cnt -= nd[i].size();	
		for(int x: nd[i]){
			tot += fdist(x,i) - 1;
		}
	}
	cout << ans << '\n';
}

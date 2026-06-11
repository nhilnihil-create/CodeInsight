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
#define MOD 1000000007
#define MAXN 52
#define MAXH 20
#define MAXM 52
#define INF 100000000
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
const int M = 100005;

bool comp(const pii &a,const pii &b){
	return (a.S - a.F) < (b.S - b.F);	
}

int t[M];

int query(int x){
	int res = 0;
	for(;x;x&=x-1){
		res += t[x];	
	}
	return res;
}

void update(int x,int val){
	for(;x < M;x+=(x&-x)){
		t[x]+=val;
	}
}


int main(){
	fast_io();
	int n,m;
	cin >> n >> m;
	vector<pii> v(n);
	cu(i,0,n){
		cin >> v[i].F >> v[i].S;
	}
	int ind = 0;
	sort(all(v), comp);
	fu(i,1,m){
		while(ind < v.size() && v[ind].S - v[ind].F + 1 < i){
			update(v[ind].F, 1);
			update(v[ind].S + 1, -1);
			++ind;
		}
		int ans = v.size() - ind;
		for(int j = i;j <= m;j+=i){
			ans += query(j);
		}
		cout << ans << '\n';
	}
}


#pragma GCC Optimize("Ofast")
#pragma GCC Optimize "trapv"
#pragma comment(linker, "/STACK: 2000000")

#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> 

using namespace std;
//using namespace boost::multiprecision; 

#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define TC int t; cin >> t; while(t--)
#define li long int
#define ll long long
#define ull unsigned long long 
#define Vec(x) vector <x>
#define Pai(x,y) pair <x,y>
#define Map(x,y) map <x,y>
#define UMap(x,y) unordered_map <x,y>
#define Set(x) set <x>
#define Sta(x) stack <x>
#define Qu(x) queue <x>https://discuss.codechef.com/t/bytelandian-gold-coins/76721
#define DQ(x) deque(x)
#define PriorQ(x)	priority_queue <x>
#define bg begin()
#define ed end()
#define sz size()
#define ct(x) count(x)
#define len length()
#define F first
#define S second
#define Makep make_pair
#define ins(x) insert(x)
#define ers(x) erase(x)
#define endl "\n";
#define MOD 1000000007
#define PI 2*acos(0.0)
#define clr() clear()
#define fori0(n) for(int i=0;i<n;i++)
#define foriab(a,b) for(int i=a;i<b;i++)
#define mem0(x) memset(x,0,sizeof(x))
#define mem1(x) memset(x,1,sizeof(x))
#define autoit(x) for(auto it=x.bg;it!=x.ed;it++)
#define count0(x) __builtin_popcount(x)
#define ret return 
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());

const ll Inf=1e9+5;
const ll m = 1e9 + 7;

namespace funset{
bool checkvow(char x){
	return ((0x208222)>>(x&(0x1f)))&1;
	}
ll highpow2(ll x){
	return (x&~(x-1));
	}
bool chk2(ll x){
		return (x&(x-1));
	}	
}

const ll Mxn = 2 * 1e5;


using namespace funset;


ll strhash(string s){
	const ll p = 31;
	const ll m = 1e9 + 7;
	ll hashval = 0;
	ll powe = 1;
	for (char c: s){
		hashval = (hashval + (c - 'a' + 1) * powe) % m;
		powe = (powe * p) % m;
	}
	return hashval;
}

ll fact(ll n){
	if(n <= 1)
		return 1;
	return n*fact(n-1);
}


ll a[1000], dp[1000], n;

ll foo(ll a, ll b, ll x, ll y, ll n){
	ll t=min(a-x,n);
	a-=t;
	n-=t;
	t = min(b-y, n);
	b-=t;
	return a*b;
}

void solve(){
	ll n;
	cin >> n;
	ll a[n];
	for(ll &i:a)
		cin >> i;
	ll m;
	cin >> m;
	ll ans  =0, k= accumulate(a,a+n, 0);
	while(m--){
		ll pi, xi;
		cin >> pi >> xi;
		--pi;
		ans = (k-a[pi])+xi;
		cout << ans << endl;
	}
}

int main(){
	//sieve();
	auto beg=clock();
	FAST
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	
    solve();
	auto ted=clock();
	#ifndef ONLINE_JUDGE
	cout << (double)(ted-beg)/CLOCKS_PER_SEC << endl;
	#endif
	ret 0;
}
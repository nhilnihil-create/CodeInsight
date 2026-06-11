#include<bits/stdc++.h>
using namespace std;

#define fastio 			ios::sync_with_stdio(0);	cin.tie(0); cout.tie(0);  cout<<fixed;  cout<<setprecision(12);	
#define randomINT 		mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define	newl 			cout<<"\n"
#define DISP(as)		for(auto it : as) cout<<it<<" ";newl;
#define all(x)         	(x).begin(),(x).end()
#define mset(x,val)    	memset(x,val,sizeof(x))
#define newl           	cout<<"\n"
#define pb             	push_back
#define mp             	make_pair
#define f 				first
#define s 				second
#define dline          cerr<<"///REACHED///\n";
#define deb1(x)        cerr<<#x<<" = "<<x<<'\n';
#define deb2(x,y)      cerr<<'['<<#x<<','<<#y<<"] = "<<'['<<x<<','<<y<<']'<<'\n';
#define deb3(x,y,z)    cerr<<'['<<#x<<','<<#y<<','<<#z<<"] = "<<'['<<x<<','<<y<<','<<z<<']'<<'\n';

typedef long long 				ll;
typedef long double 			ld;
typedef vector<ll> 				vll;
typedef pair<ll ,ll> 			pll;
typedef pair<ld,ld> 			pld;
typedef unordered_map<ll,ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	1e+5+7;
const ll 	MAX7 	= 	1e+7+7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1e+9+7;
const ll 	N 		= 	2*1e6;

vll adj[N];
ll visited[N]={};

// <------------- Declare Variables Here ------------> //

ll T=1;
ll n,x,y,m,k,q,h,s,d;
vll a,b,c;
// <------------- Implement Functions Here ----------> //
ll cost = 0;
	
ll findMIN(ll a, ll b=INF, ll c=INF, ll d=INF) {
	ll mini = min({a,b,c,d});
	if(mini == a) return 0;
	if(mini == b) return 1;
	if(mini == c) return 2;
	if(mini == d) return 3;
}

void choice(ll val, ll*n) {
	ll qty = *n;
	if(val == 0 ) {
		cost += qty*q;
		*n = (*n)%1;
	}
	if(val == 1 ) {
		qty/=2;
		cost += qty*h;
		*n = (*n)%2;
	}
	if(val == 2 ) {
		qty/=4;
		cost += qty*s;
		*n = (*n)%4;
	}
	if(val == 3 ) {
		qty/=8;
		cost += qty*d;
		*n = (*n)%8;
	}
}
// <------------- Start of main() -------------------> //

void MAIN() {
	cin>>q>>h>>s>>d>>n;
	n*=4;
	if(n >= 8) {
		ll val = findMIN(q*8,h*4,s*2,d);
		choice(val,&n);
	}

	if(n >= 4) {
		ll val = findMIN(q*8,h*4,s*2);
		choice(val,&n);
	}
	if(n >= 2) {
		ll val = findMIN(q*8,h*4);
		choice(val,&n);
	}
	if(n >= 1) {
		ll val = findMIN(q*8);
		choice(val,&n);
	}

	cout<<cost;newl;
}

int main() {
	fastio;randomINT;
	//cin>>T;
	while(T--) {
		MAIN();
	}
	return 0;
}


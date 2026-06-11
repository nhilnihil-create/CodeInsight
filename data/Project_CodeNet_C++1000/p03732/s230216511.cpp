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
typedef pair<ll , ll> 			pll;
typedef pair<ld, ld> 			pld;
typedef unordered_map<ll, ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	1e+5 + 7;
const ll 	MAX7 	= 	1e+7 + 7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1e+9 + 7;

int dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};

// <------------- Declare Variables Here ------------> //

ll T = 1;
ll n, v, m, x, y, q, k, W;
string s, t, s0, s1, s2;

vll w[4];

// <------------- Implement Functions Here ----------> //



// <------------- Start of main() -------------------> //

void MAIN() {
	cin >> n >> W;
	cin >> x >> v;
	ll w1 = x;
	w[0].pb(v);

	for (ll i = 1; i < n; i++) {
		cin >> x >> v;
		w[x - w1].pb(v);
	}

	for (ll i = 0; i < 4; i++) {
		sort(all(w[i]));
		reverse(all(w[i]));
		w[i].insert(w[i].begin(), 0);

		for (ll j = 1; j < w[i].size(); j++) w[i][j] += w[i][j - 1];
	}

	ll maxi = 0;

	for (ll a = 0; a < w[0].size(); a++) {
		for (ll b = 0; b < w[1].size(); b++) {
			for (ll c = 0; c < w[2].size(); c++) {
				for (ll d = 0; d < w[3].size(); d++) {
					if (a * (w1) + b * (w1 + 1) + c * (w1 + 2) + d * (w1 + 3) > W) break;
					maxi = max(maxi, w[0][a] + w[1][b] + w[2][c] + w[3][d]);
				}
			}
		}
	}
	cout << maxi;
}

int main() {
	fastio; randomINT;
	//cin >> T;
	while (T--) {
		MAIN();
	}
	return 0;
}

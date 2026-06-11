#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define li long long
#define ld long double
#define x first
#define y second
#define pt pair<int, int>
#define pll pair<li, li>
#define forn(i, t) for(int i = 0; i < (t); i++)
#define fore(i, f, t) for(int i = (f); i < (t); i++)
#define forr(i, f, t) for(int i = (f) - 1; i >= (t); i--)
#define all(x) (x).begin(), (x).end()
#define ins insert

using namespace std;


const int INF = 1e9;
const int MOD = 1e9 + 7;
const li INF64 = 1e18;
const ld EPS = 1e-7;

mt19937 myrand(time(NULL));

li n, a, b, c, d;


bool read(){
	if(scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d) != 5)
		return 0;
	b -= a;
	return 1;
}


void solve(){
	forn(i, n){
		li l1 = c * i, r1 = d * i;
		li l2 = (n - 1 - i) * c, r2 = (n - 1 - i) * d;
		if (l1 - r2 <= b && b <= r1 - l2){
			puts("YES");
			return;
		}
	}
	puts("NO");
}


int main(){
	#ifdef _DEBUG
		freopen("input.txt", "r", stdin);
	#endif
	while(read())
		solve();
	return 0;
}
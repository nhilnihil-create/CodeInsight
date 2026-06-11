#include<bits/stdc++.h>

using namespace std;
#define REPP(i,a,b,c) for(int i=a; i<=b; i+=c)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,c) for(int i=a; i>=b; i-=c)
#define REV(i,a,b) REVV(i,a,b,1)
#define FOR(i,a) REP(i,0,(int)a-1)
#define FORD(i,a) REV(i,(int)a-1,0)
#define PB push_back
#define POB pop_back
#define FI first
#define SE second
#define MP make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair < int , int > pii;
typedef vector < int > vi;
typedef vector < pii > vii;
typedef vector < ll > vl;
typedef pair < ll , ll > pll;

const double PI = acos(-1);
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
const int INF = 1e9;


ll addMod(ll a, ll b){
	if(a + b >= MOD) return a + b - MOD;
	return a + b;
}

ll mulMod(ll a, ll b){
	return (a*b)%MOD;
}

ll fast(ll a, ll b){
	if(b == 0) return 1;
	ll tmp = fast(a,b/2);
	tmp = mulMod(tmp,tmp);
	if(b & 1) tmp = mulMod(tmp,a);
	return tmp;
}

ll GCD(ll a, ll b){
	if(a > b) return GCD(b,a);
	if(a == 0) return b;
	return GCD(b%a,a);
}

//////////////////////////////////////////////

const int N = 1e5;

int n;
int a[N + 5];

bool solve(){
	ll tot = 0;
	REP(i,1,n){
		tot += a[i];
	}
	if(tot % ((ll)n * (n + 1) / 2) != 0) return false;
	ll cnt = tot / ((ll)n * (n + 1) / 2);
	REP(i,2,n){
		ll dif = a[i] - a[i-1];
		if(cnt - dif < 0) return false;
		if((cnt - dif) % n != 0) return false;
	}
	return true;
}

int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	REP(i,1,n) cin >> a[i];
	if(solve()) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
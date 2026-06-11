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
#define MP make_pair
#define FI first
#define SE second
typedef long long ll;
typedef unsigned long long ull;
typedef pair < int , int > pii;
typedef vector < int > vi;
typedef vector < pii > vii;
typedef vector < ll > vl;

const double EPS = 1e-9;
const double PI = acos(-1);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

ll addMod(ll a, ll b){
	return (a+b) % MOD;
}

ll mulMod(ll a, ll b){
	return (a*b) % MOD;
}

/////////////////////////////////////////////////////////

const int N = 1e5;

int n, m;
int arr[N + 5];
vi lst;


int solve(){
	int mx = 0, dif = 0;
	FORD(i,n){
		if(mx > arr[i]){
			lst.PB(mx-arr[i]);
			dif = max(dif, mx-arr[i]);
		}
		mx = max(mx, arr[i]);
	}
	sort(lst.begin(), lst.end());
	int ret = 0;
	FORD(i,lst.size()){
		if(lst[i] == dif) ret++;
	}
	return ret;
}

int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	FOR(i,n){
		cin >> arr[i];
	}
	cout << solve() << endl;
	return 0;
}
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

ll fast(ll a, ll b){
	if(b == 0) return 1;
	ll tmp = fast(a,b/2);
	tmp = mulMod(tmp, tmp);
	if(b % 2 == 1) tmp = mulMod(tmp,a);
	return tmp;
}

/////////////////////////////////////////////////////////

const int N = 5000;

ll dp[3][N + 5];
int n;
string str;

void precompute(){
	int bi = 0;
	dp[0][0] = 1;
	REP(use,1,n){
		REP(len,0,use){
			dp[1^bi][len] = dp[bi][len+1];
			if(len == 0) dp[1^bi][len] = addMod(dp[1^bi][len], dp[bi][0]);
			else dp[1^bi][len] = addMod(dp[1^bi][len], mulMod(2,dp[bi][len-1]));
		}
		bi ^= 1;
	}
}

ll solve(){
	precompute();
	return mulMod(dp[n%2][(int)str.length()], fast(fast(2, (int)str.length()), MOD-2));
}

int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> str;
	cout << solve() << endl;
	return 0;
}
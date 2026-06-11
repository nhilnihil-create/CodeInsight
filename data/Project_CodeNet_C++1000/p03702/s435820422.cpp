#include "bits/stdc++.h"
#define fcout(d) cout << fixed << setprecision(d)
#define repU(i,s,t) for(int i = (int)(s); i <= (int)(t); ++i)
#define repD(i,t,s) for(int i = (int)(t); i >= (int)(s); --i)
#define rep(i,n) repU(i,0,n - 1)
#define rep1(i,n) repU(i,1,n)
#define all(v) begin(v),end(v)
#define vct vector
#define prique priority_queue
#define l_bnd lower_bound
#define u_bnd upper_bound
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define q_ceil(n,d) ((n) > 0 ? ((n) - 1) / (d) + 1 : (n) / (d))
#define parity(a,b) (a & 1 == b & 1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const pii dir[] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const int inf32 = (1 << 30) - 1;
const ll inf64 = (1LL << 62) - 1;
const int mod = 1e9 + 7;

int N,A,B,h[100100];

bool judge(ll n){
	ll s = 0;
	rep(i,N){
		s += max(0ll,q_ceil(h[i] - n * B,A - B));
		if(s > n) return 0;
	}
	return 1;
}

int solve(){
	ll upper = inf32;
	ll lower = 0;
	while(upper - lower > 1){
		ll mid = (upper + lower) / 2;
		if(judge(mid)) upper = mid;
		else lower = mid;
	}
	return upper;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
		
	cin >> N >> A >> B;
	rep(i,N) cin >> h[i];
	cout << solve() << endl;
}


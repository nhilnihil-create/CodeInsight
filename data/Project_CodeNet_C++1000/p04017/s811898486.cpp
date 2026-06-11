#include<bits/stdc++.h>
#define rep(i, n) for(int i=0;i<(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define repa(i, n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define bit(x) (1ll << (x))
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9+7;
//const ll MOD = 998244353;
const int INF = (ll)1e9+7;
const ll INFLL = (ll)1e18;
using namespace std;
template<class t>
using vvector = vector<vector<t>>;
template<class t>
using vvvector = vector<vector<vector<t>>>;
template<class t>
using priority_queuer = priority_queue<t, vector<t>, greater<t>>;
template<class t, class u> bool chmax(t &a, u b){if(a<b){a=b;return true;}return false;}
template<class t, class u> bool chmin(t &a, u b){if(a>b){a=b;return true;}return false;}

#ifdef DEBUG
#define OUTPUT(x) (output(x), outendl())
#else
#define OUTPUT(x) (void)0
#endif

ll modpow(ll x, ll b){
	ll res = 1;
	while(b){
		if(b&1)res = res * x % MOD;
		x = x * x % MOD;
		b>>=1;
	}
	return res;
}

ll modinv(ll x){
	return modpow(x, MOD-2);
}

bool was_output = false;
template<class t>
void output(t a){
	if(was_output)cout << " ";
	cout << a;
	was_output = true;
}
void outendl(){
	was_output = false;
	cout << endl;
}

int n;
vector<int> hotel;
vector<ll> sum;
int l;

vvector<int> dp;

int func(int place, int remain){
	if(place==n+1)return n+1;
	if(dp[place][remain]>=0)return dp[place][remain];
	if(remain>0){
		return dp[place][remain] = func(func(place, remain-1), remain-1);
	}
	int p = upper_bound(all(sum), sum[place]+l) - sum.begin() - 1;
	return dp[place][remain] = p;
}

int main(){
	cin >> n;
	hotel.resize(n);
	sum.resize(n+2);
	rep(i, n){
		cin >> hotel[i];
		sum[i+1] = hotel[i];
	}
	sum[0] = 0;
	sum[n+1] = INFLL;
	dp.resize(n+4, vector<int>(30, -1));
	cin >> l;
	int q;
	cin >> q;
	rep(i, q){
		int a, b;
		cin >> a >> b;
		if(a>b)swap(a, b);
		int ans = 0;
		per(j, 29){
			if(func(a, j)>=b)continue;
			a = func(a, j);
			ans += bit(j);
		}
		if(a!=b)++ans;
		cout << ans << endl;
	}

	return 0;
}

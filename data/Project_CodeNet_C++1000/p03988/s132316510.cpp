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

int main(){
	int n;
	cin >> n;
	vector<int> line(n);
	int max_ai = 0;
	foreach(i, line){
		cin >> i;
		chmax(max_ai, i);
	}
	vector<int> cnt(max_ai+1, 0);
	foreach(i, line){
		if(max_ai/2>i){
			cout << "Impossible" << endl;
			return 0;
		}
		chmin(i, max_ai-i);
		if(cnt[i]){
			++cnt[max_ai-i];
		}else{
			++cnt[i];
		}
	}
	bool flag = true;
	foreach(i, cnt){
		if(i==0){
			flag = false;
		}
	}
	if(max_ai&1){
		flag &= cnt[max_ai/2] == 1 && cnt[max_ai/2+1] == 1;
	}else{
		flag &= cnt[max_ai/2] == 1;
	}
	if(flag){
		cout << "Possible" << endl;
	}else{
		cout << "Impossible" << endl;
	}
	return 0;
}

